#ifndef _Secondary_hh_
#define _Secondary_hh_
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <string>
#include <cstdlib>
#include <iostream>
#include <marlin/Processor.h>
#include <vector>
#include "TFile.h"
#include "TTree.h"
#include <cmath>
#include <EVENT/LCIO.h>
#include <EVENT/LCCollection.h>
#include <IMPL/LCCollectionVec.h>
#include <EVENT/MCParticle.h>
#include "MathOperator.hh"
#include <EVENT/CalorimeterHit.h>
#include <IMPL/CalorimeterHitImpl.h>
#include <UTIL/CellIDDecoder.h>
#include "Calorimeter.hh"
using MyCalorimeter::MathOperator;

namespace CALICE {

	class SecondariesAnalyser : public marlin::Processor 
	{
	public:
		//
		//	Constructor & Destructor
		//
		SecondariesAnalyser ();
		virtual ~SecondariesAnalyser (){};
		//
		//	Methods
		//
		Processor*  newProcessor() { return new SecondariesAnalyser ; }
		/** Called at the begin of the job before anything is read.
		 *  * Use to initialize the processor, e.g. book histograms.
		 *   */
		void init();
		/** Called for every run, e.g. overwrite to initialize run dependent 
		 *  *  histograms.
		 *   */
		void processRunHeader( LCRunHeader* run);

		/** Called for every event - the working horse. 
		 *  */
		void processEvent( LCEvent * evtP );

		//Called at the end of the job
		void end();
		
	private:
		//
		//	Methods
		//
		void processMCparticles(LCEvent * evt);
		bool applyPrimaryCutsTo(MCParticle * particle);
		void writeParticle(MCParticle * particle, int i);
		int applyIntegrationCuts(const vector<MCParticle*> & particle);

		//
		//	Data
		//
		int _eventNumber;
		
		int LastFiredPadsNumber;
		int LastEventsFromLayer;
		int FirstInteractionLayer;
		int RequireInteraction;

		MyCalorimeter::Calorimeter ECalCopy;
		
		float _angleCut;
		float _ekinCut;
		float _distanceCut;

		static const int MAXN = 10000 ;
		int _nMCparticlesTrue;
		int _nMCparticles;
		int _numberMCP_corrected;
		float _startY[MAXN];
		float _startX[MAXN];
		float _startZ[MAXN];
		float _endY[MAXN];
		float _endX[MAXN];
		float _endZ[MAXN];
		float _energy[MAXN];
		float _energy_kin[MAXN];
		float _mass[MAXN];
		float _zmomentum[MAXN];
		int _charge[MAXN];
		float _distance[MAXN];
		vector< vector< float > > * volumeECal;
		TTree* _MCTree;
		TFile* hfile ;
		/* data */
	};

} // CALICE
#endif
