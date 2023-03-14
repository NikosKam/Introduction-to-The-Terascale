#include <iostream>
#include <stdio.h>
#include <string>

#include <TROOT.h>
#include <TFile.h>
#include <TH1F.h>
#include <TH1I.h>
#include "TLegend.h"
#include "TLegendEntry.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TStyle.h"

TTree *events;
TFile *fp;

using namespace std;

//Declaration of leaves types
Int_t           NJet;
Float_t         Jet_Px[10];
Float_t         Jet_Py[10];
Float_t         Jet_Pz[10];
Float_t         Jet_E[10];
Float_t         Jet_btag[10];
Bool_t          Jet_ID[10];
Int_t           NMuon;
Float_t         Muon_Px[3];
Float_t         Muon_Py[3];
Float_t         Muon_Pz[3];
Float_t         Muon_E[3];
Int_t           Muon_Charge[3];
Float_t         Muon_Iso[3];
Int_t           NElectron;
Float_t         Electron_Px[2];
Float_t         Electron_Py[2];
Float_t         Electron_Pz[2];
Float_t         Electron_E[2];
Int_t           Electron_Charge[2];
Float_t         Electron_Iso[2];
Int_t           NPhoton;
Float_t         Photon_Px[2];
Float_t         Photon_Py[2];
Float_t         Photon_Pz[2];
Float_t         Photon_E[2];
Float_t         Photon_Iso[2];
Float_t         MET_px;
Float_t         MET_py;
Float_t         MChadronicBottom_px;
Float_t         MChadronicBottom_py;
Float_t         MChadronicBottom_pz;
Float_t         MCleptonicBottom_px;
Float_t         MCleptonicBottom_py;
Float_t         MCleptonicBottom_pz;
Float_t         MChadronicWDecayQuark_px;
Float_t         MChadronicWDecayQuark_py;
Float_t         MChadronicWDecayQuark_pz;
Float_t         MChadronicWDecayQuarkBar_px;
Float_t         MChadronicWDecayQuarkBar_py;
Float_t         MChadronicWDecayQuarkBar_pz;
Float_t         MClepton_px;
Float_t         MClepton_py;
Float_t         MClepton_pz;
Int_t           MCleptonPDGid;
Float_t         MCneutrino_px;
Float_t         MCneutrino_py;
Float_t         MCneutrino_pz;
Int_t           NPrimaryVertices;
Bool_t          triggerIsoMu24;
Float_t         EventWeight;

void init()
{
   // Set branch addresses
   events->SetBranchAddress("NJet",&NJet);
   events->SetBranchAddress("Jet_Px",Jet_Px);
   events->SetBranchAddress("Jet_Py",Jet_Py);
   events->SetBranchAddress("Jet_Pz",Jet_Pz);
   events->SetBranchAddress("Jet_E",Jet_E);
   events->SetBranchAddress("Jet_btag",Jet_btag);
   events->SetBranchAddress("Jet_ID",Jet_ID);
   events->SetBranchAddress("NMuon",&NMuon);
   events->SetBranchAddress("Muon_Px",Muon_Px);
   events->SetBranchAddress("Muon_Py",Muon_Py);
   events->SetBranchAddress("Muon_Pz",Muon_Pz);
   events->SetBranchAddress("Muon_E",Muon_E);
   events->SetBranchAddress("Muon_Charge",Muon_Charge);
   events->SetBranchAddress("Muon_Iso",Muon_Iso);
   events->SetBranchAddress("NElectron",&NElectron);
   events->SetBranchAddress("Electron_Px",Electron_Px);
   events->SetBranchAddress("Electron_Py",Electron_Py);
   events->SetBranchAddress("Electron_Pz",Electron_Pz);
   events->SetBranchAddress("Electron_E",Electron_E);
   events->SetBranchAddress("Electron_Charge",Electron_Charge);
   events->SetBranchAddress("Electron_Iso",Electron_Iso);
   events->SetBranchAddress("NPhoton",&NPhoton);
   events->SetBranchAddress("Photon_Px",Photon_Px);
   events->SetBranchAddress("Photon_Py",Photon_Py);
   events->SetBranchAddress("Photon_Pz",Photon_Pz);
   events->SetBranchAddress("Photon_E",Photon_E);
   events->SetBranchAddress("Photon_Iso",Photon_Iso);
   events->SetBranchAddress("MET_px",&MET_px);
   events->SetBranchAddress("MET_py",&MET_py);
   events->SetBranchAddress("MChadronicBottom_px",&MChadronicBottom_px);
   events->SetBranchAddress("MChadronicBottom_py",&MChadronicBottom_py);
   events->SetBranchAddress("MChadronicBottom_pz",&MChadronicBottom_pz);
   events->SetBranchAddress("MCleptonicBottom_px",&MCleptonicBottom_px);
   events->SetBranchAddress("MCleptonicBottom_py",&MCleptonicBottom_py);
   events->SetBranchAddress("MCleptonicBottom_pz",&MCleptonicBottom_pz);
   events->SetBranchAddress("MChadronicWDecayQuark_px",&MChadronicWDecayQuark_px);
   events->SetBranchAddress("MChadronicWDecayQuark_py",&MChadronicWDecayQuark_py);
   events->SetBranchAddress("MChadronicWDecayQuark_pz",&MChadronicWDecayQuark_pz);
   events->SetBranchAddress("MChadronicWDecayQuarkBar_px",&MChadronicWDecayQuarkBar_px);
   events->SetBranchAddress("MChadronicWDecayQuarkBar_py",&MChadronicWDecayQuarkBar_py);
   events->SetBranchAddress("MChadronicWDecayQuarkBar_pz",&MChadronicWDecayQuarkBar_pz);
   events->SetBranchAddress("MClepton_px",&MClepton_px);
   events->SetBranchAddress("MClepton_py",&MClepton_py);
   events->SetBranchAddress("MClepton_pz",&MClepton_pz);
   events->SetBranchAddress("MCleptonPDGid",&MCleptonPDGid);
   events->SetBranchAddress("MCneutrino_px",&MCneutrino_px);
   events->SetBranchAddress("MCneutrino_py",&MCneutrino_py);
   events->SetBranchAddress("MCneutrino_pz",&MCneutrino_pz);
   events->SetBranchAddress("NPrimaryVertices",&NPrimaryVertices);
   events->SetBranchAddress("triggerIsoMu24",&triggerIsoMu24);
   events->SetBranchAddress("EventWeight",&EventWeight);
}

// setTDRStyle and init declared here, implementated in the end of this file
void setTDRStyle(); 
void init(TTree *events); 


// store weighted event counts and their error
//Double_t counts[nFiles+1]; // last is for all MCs summed
//Double_t countsError[nFiles+1]; 

void ex1()
{
    // set style for the plots
    setTDRStyle();
    gStyle->SetOptTitle(0);

    fp = TFile::Open("http://theofil.web.cern.ch/theofil/cmsod/files/ttbar.root", "READ");
    events = (TTree*)fp->Get("events");
    init();
  
    float N = events -> GetEntries();

    float n = events->GetEntries("abs(MCleptonPDGid) == 13 && MCleptonPDGid != 0");

    float p = n/N;

    float s = sqrt(p*(1-p)/N);

    TCanvas *c1 = new TCanvas("c1","",800,800);
    events -> Draw("MCleptonPDGid","abs(MCleptonPDGid) == 13 && triggerIsoMu24 == 1");

    TCanvas *c2 = new TCanvas("c2","",800,800);
    TH1F *h1 =  new TH1F("h1","P_{T};p_{T};events",100, 0,200);
    TH1F *h2 =  new TH1F("h2","MC;p_{T};events",100, 0,200);

    events->Draw("sqrt(MClepton_px*MClepton_px+MClepton_py*MClepton_py)>>h1","abs(MCleptonPDGid) ==13 && triggerIsoMu24 == 1");
    events->Draw("sqrt(Muon_Px*Muon_Px+Muon_Py*Muon_Py)>>h2","abs(MCleptonPDGid) ==13 && triggerIsoMu24 == 1");

    h1->Draw("samePLC e1");
    h2->Draw("samePLC hist");

    printf("%f +/- %f", p, s);

    float w = events->GetEntries("abs(MCleptonPDGid) == 13 && NMuon==1 && triggerIsoMu24 == 1");
    float BR = w/N;

    printf("/ BR(ttbar->mu) = %f", BR);

}

// setTDRStyle for the plots
void setTDRStyle() 
{
  TStyle *tdrStyle = new TStyle("tdrStyle","Style for P-TDR");

  // For the canvas:
  tdrStyle->SetCanvasBorderMode(0);
  tdrStyle->SetCanvasColor(kWhite);
  tdrStyle->SetCanvasDefH(600); //Height of canvas
  tdrStyle->SetCanvasDefW(600); //Width of canvas
  tdrStyle->SetCanvasDefX(0);   //POsition on screen
  tdrStyle->SetCanvasDefY(0);

  // For the Pad:
  tdrStyle->SetPadBorderMode(0);
  tdrStyle->SetPadColor(kWhite);
  tdrStyle->SetPadGridX(false);
  tdrStyle->SetPadGridY(false);
  tdrStyle->SetGridColor(0);
  tdrStyle->SetGridStyle(3);
  tdrStyle->SetGridWidth(1);

  // For the frame:
  tdrStyle->SetFrameBorderMode(0);
  tdrStyle->SetFrameBorderSize(1);
  tdrStyle->SetFrameFillColor(0);
  tdrStyle->SetFrameFillStyle(0);
  tdrStyle->SetFrameLineColor(1);
  tdrStyle->SetFrameLineStyle(1);
  tdrStyle->SetFrameLineWidth(1);

  tdrStyle->SetHistLineColor(1);
  tdrStyle->SetHistLineStyle(0);
  tdrStyle->SetHistLineWidth(1);

  tdrStyle->SetEndErrorSize(2);
  tdrStyle->SetErrorX(0.);
  
  tdrStyle->SetMarkerStyle(20);
  tdrStyle->SetMarkerSize(1.2);

  //For the fit/function:
  tdrStyle->SetOptFit(1);
  tdrStyle->SetFitFormat("5.4g");
  tdrStyle->SetFuncColor(2);
  tdrStyle->SetFuncStyle(1);
  tdrStyle->SetFuncWidth(1);

  //For the date:
  tdrStyle->SetOptDate(0);

  // For the statistics box:
  tdrStyle->SetOptFile(0);
  tdrStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  tdrStyle->SetStatColor(kWhite);
  tdrStyle->SetStatFont(42);
  tdrStyle->SetStatFontSize(0.025);
  tdrStyle->SetStatTextColor(1);
  tdrStyle->SetStatFormat("6.4g");
  tdrStyle->SetStatBorderSize(1);
  tdrStyle->SetStatH(0.1);
  tdrStyle->SetStatW(0.15);

  // Margins:
  tdrStyle->SetPadTopMargin(0.05);
  tdrStyle->SetPadBottomMargin(0.13);
  tdrStyle->SetPadLeftMargin(0.13);
  tdrStyle->SetPadRightMargin(0.05);

  // For the Global title:

  //  tdrStyle->SetOptTitle(0);
  tdrStyle->SetTitleFont(42);
  tdrStyle->SetTitleColor(1);
  tdrStyle->SetTitleTextColor(1);
  tdrStyle->SetTitleFillColor(10);
  tdrStyle->SetTitleFontSize(0.05);

  // For the axis titles:

  tdrStyle->SetTitleColor(1, "XYZ");
  tdrStyle->SetTitleFont(42, "XYZ");
  tdrStyle->SetTitleSize(0.06, "XYZ");
  tdrStyle->SetTitleXOffset(0.9);
  tdrStyle->SetTitleYOffset(1.05);

  // For the axis labels:

  tdrStyle->SetLabelColor(1, "XYZ");
  tdrStyle->SetLabelFont(42, "XYZ");
  tdrStyle->SetLabelOffset(0.007, "XYZ");
  tdrStyle->SetLabelSize(0.05, "XYZ");

  // For the axis:

  tdrStyle->SetAxisColor(1, "XYZ");
  tdrStyle->SetStripDecimals(kTRUE);
  tdrStyle->SetTickLength(0.03, "XYZ");
  tdrStyle->SetNdivisions(510, "XYZ");
  tdrStyle->SetPadTickX(1);  // To get tick marks on the opposite side of the frame
  tdrStyle->SetPadTickY(1);

  // Change for log plots:
  tdrStyle->SetOptLogx(0);
  tdrStyle->SetOptLogy(0);
  tdrStyle->SetOptLogz(0);

  tdrStyle->cd();

  // --- set nice colors in 2D

  const Int_t NRGBs = 5;
  const Int_t NCont = 255;

  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
  gStyle->SetNumberContours(NCont);

  // --- set default Sumw2
  TH1::SetDefaultSumw2(true);
}

void init(TTree *events)
{
   // Set branch addresses
   events->SetBranchAddress("NJet",&NJet);
   events->SetBranchAddress("Jet_Px",Jet_Px);
   events->SetBranchAddress("Jet_Py",Jet_Py);
   events->SetBranchAddress("Jet_Pz",Jet_Pz);
   events->SetBranchAddress("Jet_E",Jet_E);
   events->SetBranchAddress("Jet_btag",Jet_btag);
   events->SetBranchAddress("Jet_ID",Jet_ID);
   events->SetBranchAddress("NMuon",&NMuon);
   events->SetBranchAddress("Muon_Px",Muon_Px);
   events->SetBranchAddress("Muon_Py",Muon_Py);
   events->SetBranchAddress("Muon_Pz",Muon_Pz);
   events->SetBranchAddress("Muon_E",Muon_E);
   events->SetBranchAddress("Muon_Charge",Muon_Charge);
   events->SetBranchAddress("Muon_Iso",Muon_Iso);
   events->SetBranchAddress("NElectron",&NElectron);
   events->SetBranchAddress("Electron_Px",Electron_Px);
   events->SetBranchAddress("Electron_Py",Electron_Py);
   events->SetBranchAddress("Electron_Pz",Electron_Pz);
   events->SetBranchAddress("Electron_E",Electron_E);
   events->SetBranchAddress("Electron_Charge",Electron_Charge);
   events->SetBranchAddress("Electron_Iso",Electron_Iso);
   events->SetBranchAddress("NPhoton",&NPhoton);
   events->SetBranchAddress("Photon_Px",Photon_Px);
   events->SetBranchAddress("Photon_Py",Photon_Py);
   events->SetBranchAddress("Photon_Pz",Photon_Pz);
   events->SetBranchAddress("Photon_E",Photon_E);
   events->SetBranchAddress("Photon_Iso",Photon_Iso);
   events->SetBranchAddress("MET_px",&MET_px);
   events->SetBranchAddress("MET_py",&MET_py);
   events->SetBranchAddress("MChadronicBottom_px",&MChadronicBottom_px);
   events->SetBranchAddress("MChadronicBottom_py",&MChadronicBottom_py);
   events->SetBranchAddress("MChadronicBottom_pz",&MChadronicBottom_pz);
   events->SetBranchAddress("MCleptonicBottom_px",&MCleptonicBottom_px);
   events->SetBranchAddress("MCleptonicBottom_py",&MCleptonicBottom_py);
   events->SetBranchAddress("MCleptonicBottom_pz",&MCleptonicBottom_pz);
   events->SetBranchAddress("MChadronicWDecayQuark_px",&MChadronicWDecayQuark_px);
   events->SetBranchAddress("MChadronicWDecayQuark_py",&MChadronicWDecayQuark_py);
   events->SetBranchAddress("MChadronicWDecayQuark_pz",&MChadronicWDecayQuark_pz);
   events->SetBranchAddress("MChadronicWDecayQuarkBar_px",&MChadronicWDecayQuarkBar_px);
   events->SetBranchAddress("MChadronicWDecayQuarkBar_py",&MChadronicWDecayQuarkBar_py);
   events->SetBranchAddress("MChadronicWDecayQuarkBar_pz",&MChadronicWDecayQuarkBar_pz);
   events->SetBranchAddress("MClepton_px",&MClepton_px);
   events->SetBranchAddress("MClepton_py",&MClepton_py);
   events->SetBranchAddress("MClepton_pz",&MClepton_pz);
   events->SetBranchAddress("MCleptonPDGid",&MCleptonPDGid);
   events->SetBranchAddress("MCneutrino_px",&MCneutrino_px);
   events->SetBranchAddress("MCneutrino_py",&MCneutrino_py);
   events->SetBranchAddress("MCneutrino_pz",&MCneutrino_pz);
   events->SetBranchAddress("NPrimaryVertices",&NPrimaryVertices);
   events->SetBranchAddress("triggerIsoMu24",&triggerIsoMu24);
   events->SetBranchAddress("EventWeight",&EventWeight);
}
