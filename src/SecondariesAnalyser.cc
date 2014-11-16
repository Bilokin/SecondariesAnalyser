#include "SecondariesAnalyser.hh"
using std::cout;
using std::vector;
using std::string;
using std::endl;
namespace CALICE {

	SecondariesAnalyser a_SecondariesAnalyser_instance;

	SecondariesAnalyser::SecondariesAnalyser() : Processor("MySecondariesAnalyser")
	{
		_eventNumber = 0;
		
		_angleCut = 0.2;
		_ekinCut = 0.2;
		_distanceCut = 70;
		registerProcessorParameter( "RequireInteraction",
			"Select events with interaction? 0 or 1",
			RequireInteraction,
			RequireInteraction);
		registerProcessorParameter( "FirstInteractionLayer",
			"Limit on interaction layer",
			FirstInteractionLayer,
			FirstInteractionLayer);
		registerProcessorParameter( "LastFiredPadsNumber" ,
			"The maximum number of hits in last layer",
                          LastFiredPadsNumber,
                          LastFiredPadsNumber);
		LastEventsFromLayer = 25;
		registerProcessorParameter( "LastEventsFromLayer",
			"Count events from layer #",
			LastEventsFromLayer,
			LastEventsFromLayer);


		registerProcessorParameter( "angleCut",
		        "Angle integration cut MC",
		        _angleCut,
		        _angleCut);
		registerProcessorParameter( "ekinCut",
		        "E_kin cut MC",
		        _ekinCut,
		        _ekinCut);
		registerProcessorParameter( "distanceCut",
		        "distance Cut MC",
		        _distanceCut,
			_distanceCut);

	}
	void SecondariesAnalyser::init()
	{
		string _hfilename = "Secondaries.root";
		hfile = new TFile( _hfilename.c_str(), "RECREATE", _hfilename.c_str() ) ;
		_MCTree =  new TTree( "MCParticles", "My test tree!" );
		_MCTree->Branch("nMCparticles", &_nMCparticles, "nMCparticles/I");
		_MCTree->Branch("endX", _endX,"endX[nMCparticles]/F");
		_MCTree->Branch("endY", _endY,"endY[nMCparticles]/F");
		_MCTree->Branch("endZ", _endZ,"endZ[nMCparticles]/F");
		_MCTree->Branch("startX", _startX,"startX[nMCparticles]/F");
		_MCTree->Branch("startY", _startY,"startY[nMCparticles]/F");
		_MCTree->Branch("startZ", _startZ,"startZ[nMCparticles]/F");
		_MCTree->Branch("zmomentum", _zmomentum,"zmomentum[nMCparticles]/F");
		_MCTree->Branch("energy_kin",_energy_kin,"energy_kin[nMCparticles]/F");
		_MCTree->Branch("energy",_energy, "energy[nMCparticles]/F");
		_MCTree->Branch("mass",_mass, "mass[nMCparticles]/F");
		_MCTree->Branch("charge",_charge, "charge[nMCparticles]/I");
		_MCTree->Branch("distance",_distance, "distance[nMCparticles]/F");
		_MCTree->Branch("nMCparticles_corrected", &_numberMCP_corrected, "nMCparticles_corrected/I");

		printParameters();

		volumeECal = new vector< vector< float > >();
		vector< float > range;
		range.push_back(-90.0);
		range.push_back(90.0);
		volumeECal->push_back(range);
		range[0] = -90.0;
		range[1] = 90.0;
		volumeECal->push_back(range);
		range[0] = 1300.0;
		range[1] = 1500.0;
		volumeECal->push_back(range);
		int xyNumber = 18;
		int zNumber = 30;

		ECalCopy.Initialize(xyNumber,xyNumber,zNumber,volumeECal);		
	}
	void SecondariesAnalyser::processRunHeader( LCRunHeader* run)
	{
	}
	bool SecondariesAnalyser::applyPrimaryCutsTo(MCParticle * aMCparticle)
	{
		float epsilon = 0.01;
		float absCharge = abs(aMCparticle->getCharge());
		if (absCharge < 1.0-epsilon)
		{
			return false;
		}
		float Ekin = sqrt(aMCparticle->getEnergy()*aMCparticle->getEnergy()-aMCparticle->getMass()*aMCparticle->getMass());
		float dieOffset  = 50.0;
		float bornOffset = _distanceCut;
		float mcDistance = MathOperator::getDistance(aMCparticle->getVertex(),aMCparticle->getEndpoint());
		float pt =  sqrt(aMCparticle->getMomentum()[1]*aMCparticle->getMomentum()[1]+aMCparticle->getMomentum()[0]*aMCparticle->getMomentum()[0]*aMCparticle->getMomentum()[0]);
		//float tan = pt / aMCparticle->getMomentum()[2];
		return ( mcDistance > _distanceCut &&
		//Ekin > _ekinCut && mcDistance > dieOffset)&&
		//aMCparticle->getMomentum()[2]>0 &&
		aMCparticle->getVertex()[2] > volumeECal->at(2)[0] - 2*bornOffset &&
		aMCparticle->getVertex()[2] < volumeECal->at(2)[1]  - bornOffset &&

		aMCparticle->getVertex()[0] > volumeECal->at(0)[0] &&
		aMCparticle->getVertex()[0] < volumeECal->at(0)[1] &&

		aMCparticle->getVertex()[1] > volumeECal->at(1)[0] &&
		aMCparticle->getVertex()[1] < volumeECal->at(1)[1] &&

		((abs(aMCparticle->getEndpoint()[0]) > volumeECal->at(0)[1] - dieOffset ||
		abs(aMCparticle->getEndpoint()[1]) > volumeECal->at(1)[1]  - dieOffset ||
		((pt > 0.20 && Ekin > _ekinCut )||
		aMCparticle->getEndpoint()[2] > volumeECal->at(2)[1] - dieOffset)) && aMCparticle->getMass() > 0.01)); //|| 
		//(tan > _angleCut && Ekin > _ekinCut));
	}


	int SecondariesAnalyser::applyIntegrationCuts(const vector<MCParticle*> & particles)
	{
		float sineCut = _angleCut;
		float epsilon = 0.001;

		int count = 0;
		for (int i = 0; i < particles.size(); i++)
		{
			MCParticle * one = particles.at(i);
			bool notExcluded = true;
			for (int j = i+1; j < particles.size(); j++)
			{
				MCParticle * two = particles.at(j);
				if (MathOperator::approximatelyEqual(two->getVertex(), one->getVertex()))
				{
					//std::cout << "Particles start from the same pad!!!!!!!!!!!!!!!!!!!!!!!!!\n";
					vector<float> directionOne = MathOperator::getDirection(one->getVertex(),one->getEndpoint());
					float distance = MathOperator::getDistanceTo(two->getEndpoint(),directionOne, one->getEndpoint());
					//float d1 = MathOperator::getDistance(one->getVertex(),one->getEndpoint());
					float d2 = MathOperator::getDistance(two->getVertex(),two->getEndpoint());
					float sine =distance / d2;
					
					////sineCut = _angleCut / (d2 > d1)? d1 : d2;
					if (sine<sineCut)
					{
						count++;
					}
				}
				if (MathOperator::approximatelyEqual(two->getVertex(), one->getEndpoint()) && notExcluded) 
				{
					count++;
					notExcluded = false;
				}
			}
		}
		return count;
	}

	

	void SecondariesAnalyser::writeParticle(MCParticle * aMCparticle, int _nMCparticles)
	{
		_mass[_nMCparticles] = aMCparticle->getMass();
		_startX[_nMCparticles] = aMCparticle->getVertex()[0];
		_startY[_nMCparticles] = aMCparticle->getVertex()[1];
		_startZ[_nMCparticles] = aMCparticle->getVertex()[2];
		_zmomentum[_nMCparticles] = aMCparticle->getMomentum()[2];
		_endX[_nMCparticles] = aMCparticle->getEndpoint()[0];
		_endY[_nMCparticles] = aMCparticle->getEndpoint()[1];
		_endZ[_nMCparticles] = aMCparticle->getEndpoint()[2];
		_energy[_nMCparticles] = aMCparticle->getEnergy();
		_energy_kin[_nMCparticles] = sqrt(aMCparticle->getEnergy()*aMCparticle->getEnergy()-aMCparticle->getMass()*aMCparticle->getEnergy()-aMCparticle->getMass()*aMCparticle->getMass());
		_distance[_nMCparticles] = MathOperator::getDistance(aMCparticle->getVertex(), aMCparticle->getEndpoint());

	}
	void SecondariesAnalyser::processMCparticles(LCEvent * evt)
	{
		std::cout << "\n***Starting MC analisys***\n";
		EVENT::LCCollection* mcpart = evt->getCollection( "MyMCParticles" ) ;
		int numberOfMCparticles = mcpart->getNumberOfElements();
		_nMCparticles = 0;
		std::cout << "There are " << numberOfMCparticles << " MC particles:\n";
		EVENT::MCParticle* aMCparticle;
		vector<EVENT::MCParticle * > afterCutsParticles;
		for (int i = 0; i < numberOfMCparticles; i++)
		{
		        aMCparticle = dynamic_cast<EVENT::MCParticle*> ( mcpart->getElementAt(i) ) ;
			if (aMCparticle)
			{
				if (applyPrimaryCutsTo(aMCparticle))
				{
					std::cout << "Particle " << _nMCparticles++ << " has " << aMCparticle->getEnergy() << " energy and " << aMCparticle->getCharge() << " charge, mass: " << aMCparticle->getMass() << " GeV. It is decayed?: " <<aMCparticle->isDecayedInCalorimeter() <<'\n';
					float Ekin = sqrt(aMCparticle->getEnergy()*aMCparticle->getEnergy()-aMCparticle->getMass()*aMCparticle->getMass());
					std::cout << "Ekin = " << Ekin << '\n';
					//writeParticle(aMCparticle);
					afterCutsParticles.push_back(aMCparticle);
					std::cout << "My start points are: " << aMCparticle->getVertex()[0] <<' '<<aMCparticle->getVertex()[1]<<' '<<aMCparticle->getVertex()[2]<<'\n';
					std::cout << "My end points are: " << aMCparticle->getEndpoint()[0] <<' '<<aMCparticle->getEndpoint()[1]<<' '<<aMCparticle->getEndpoint()[2]<< ", my momentum: " <<aMCparticle->getMomentum()[0] <<' '<< aMCparticle->getMomentum()[1] <<' '<< aMCparticle->getMomentum()[2]<<  '\n';
					std::cout << "----\n";
				}
			}
		}
		for (int i = 0; i < afterCutsParticles.size(); i++)
		{
		        writeParticle(afterCutsParticles[i], i);
		}
		_numberMCP_corrected = _nMCparticles - applyIntegrationCuts(afterCutsParticles);
		_numberMCP_corrected = (_numberMCP_corrected < 1)? _nMCparticles : _numberMCP_corrected;
		std::cout << "***End of MC analisys***\n\n";
	}

	void SecondariesAnalyser::processEvent( LCEvent * evtP )
	{
		if(evtP)
		{
			try
			{
				string _colName = "ECALConvCalorimeterHits";
				LCCollection* col_hits = evtP->getCollection( _colName ) ;
				CellIDDecoder<CalorimeterHit> cd(col_hits);
				int IsInteraction = col_hits->parameters().getIntVal("isInteraction");
				int InteractionZ = col_hits->parameters().getIntVal("InteractionLayer");
				if (!RequireInteraction)
				{
				        IsInteraction = 1;
				        FirstInteractionLayer = 55;
				}
				//std::cout << "FirstInteractionLayer = " << FirstInteractionLayer << "InteractionZ = " << InteractionZ << '\n';
				if(IsInteraction && InteractionZ < FirstInteractionLayer)
				{

					int numberOfHits = col_hits->getNumberOfElements();
					for ( int hit_i = 0 ; hit_i < numberOfHits ; hit_i++ )
					{
						vector< float > v;
						CalorimeterHit *aHit = dynamic_cast<CalorimeterHit*>( col_hits->getElementAt( hit_i ));
						int waferx = cd(aHit)["S-1"];
						int wafery = cd(aHit)["M"]-1;
						int padx = cd(aHit)["I"]-1;
						int pady = cd(aHit)["J"]-1;
						ECalCopy.LightThePad(waferx * 6 + padx,wafery * 6 + pady, cd(aHit)["K-1"], aHit->getEnergy());
					}
					if(ECalCopy.GetNumberOfActivePadsSince(LastEventsFromLayer)>LastFiredPadsNumber)
					{
						
						std::cout << "===================================================\n";
						std::cout << "Event #" << _eventNumber++ << '\n';
						std::cout << "===================================================\n";
						processMCparticles(evtP);
						_MCTree->Fill();
					}
					ECalCopy.DimAllPads();
				}

			}
			catch(lcio::DataNotAvailableException e)
			{
			        std::cout << "Error occurred!\n";
			}

		}
	}
	void SecondariesAnalyser::end()
	{
		hfile->cd();
		hfile->Write();
		hfile->Close();
	}



} //CALICE
