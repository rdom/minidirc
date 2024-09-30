#if defined(__ACLIC__)
#include "PrtTools.h"
#else
R__LOAD_LIBRARY(../build/libPrt.so)
#endif

void draw_mult(TString infile = "../build/hits.root") {

  PrtTools t(infile);

  TH1F *hmult90 = new TH1F("hmult90", ";detected photons [#];entries [#]", 500, 550000, 650000);
  TH1F *hmult91 = new TH1F("hmult91", ";detected photons [#];entries [#]", 500, 550000, 650000);
  TH1F *hmult95 = new TH1F("hmult915", ";detected photons [#];entries [#]", 500, 550000, 650000);

  while (t.next() && t.i() < 10000) {
    hmult90->Fill(t.event()->getHits().size() * 100);
  }
  // PrtTools t1("../build/ion_91.root");
  // while (t1.next()) {
  //   hmult91->Fill(t1.event()->getHits().size() * 10);
  // }

  // PrtTools t5("../build/ion_91_5.root");
  // while (t5.next()) {
  //   hmult95->Fill(t5.event()->getHits().size() *100 );
  // }
  
  gStyle->SetOptStat(0);

  t.add_canvas("mult",1200,600);
  hmult90->Draw();
  hmult91->SetLineColor(kRed);
  hmult91->Draw("same");
  // hmult95->SetLineColor(kGreen+1);
  // hmult95->Draw("same");
  t.save_canvas("data/draw_mult", 0);
}
