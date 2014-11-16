/////////////////////////////////////////////
// Last Modified PS 19.12.2011
//  + Added TitleOffset
//  + Added gROOT->ForceStyle()
////////////////////////////////////////////

{
cout << endl << "Welcome to CMS rootlogon.C" << endl;
TStyle *cmsStyle= new TStyle("CMS","CMS approved plots style");
gROOT->SetStyle("Plain"); 
// use plain black on white colors
cmsStyle->SetFrameBorderMode(0);
cmsStyle->SetCanvasBorderMode(0);
cmsStyle->SetPadBorderMode(0);
cmsStyle->SetPadColor(0);
cmsStyle->SetCanvasColor(0);
cmsStyle->SetStatColor(0);
//cmsStyle->SetFillColor(0);

// set the paper & margin sizes
cmsStyle->SetPaperSize(20,26);
cmsStyle->SetPadTopMargin(0.05);
cmsStyle->SetPadRightMargin(0.05);
cmsStyle->SetPadBottomMargin(0.16);
cmsStyle->SetPadLeftMargin(0.12);

// use large Times-Roman fonts
cmsStyle->SetTextFont(132);
cmsStyle->SetTextSize(0.08);
cmsStyle->SetLabelFont(132,"x");
cmsStyle->SetLabelFont(132,"y");
cmsStyle->SetLabelFont(132,"z");
cmsStyle->SetTitleFont(132,"x");
cmsStyle->SetTitleFont(132,"y");
cmsStyle->SetTitleFont(132,"z");
cmsStyle->SetLabelSize(0.04,"x");
cmsStyle->SetTitleOffset(1.2,"x");
cmsStyle->SetTitleSize(0.05,"x");
cmsStyle->SetLabelSize(0.04,"y");
cmsStyle->SetTitleSize(0.05,"y");
cmsStyle->SetTitleOffset(1.2,"y");
cmsStyle->SetLabelSize(0.04,"z");
cmsStyle->SetTitleSize(0.05,"z");
cmsStyle->SetTitleOffset(1.2,"z");

// use bold lines and markers
cmsStyle->SetMarkerStyle(20);
cmsStyle->SetHistLineWidth(1.85);
cmsStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

// get rid of X error bars and y error bar caps
cmsStyle->SetErrorX(0.001);

// do not display any of the standard histogram decorations
cmsStyle->SetOptTitle(0);
cmsStyle->SetOptStat(0);
cmsStyle->SetOptFit(0);

// put tick marks on top and RHS of plots
cmsStyle->SetPadTickX(1);
cmsStyle->SetPadTickY(1);

gROOT->SetStyle("CMS");
gROOT->ForceStyle();
//gStyle->SetOptStat(1111111);

// Setup for CMSSW----
//{
//   gROOT->LoadMacro("../../Macros/test/plotHistsAndRatio.C"); 
//   AutoLibraryLoader::enable();
//   gSystem->Load("libDataFormatsFWLite.so");
//   gSystem->Load("libDataFormatsPatCandidates.so");
//}

}
