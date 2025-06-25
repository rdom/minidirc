#if defined(__ACLIC__)
#include "PrtTools.h"
#else
R__LOAD_LIBRARY(../build/libPrt.so)
#endif

void draw_time(TString infile = "../build/hits.root") {

  PrtTools t(infile);

  TH1F *hTime = new TH1F("hTime", ";propagation time [ns];entries [#]", 300, 0, 30);
  
  
  while (t.next()) {
    for (auto hit : t.event()->getHits()) {

      int ch = hit.getChannel();
      int pmt = hit.getPmt();
      int pix = hit.getPixel();
      double time = hit.getLeadTime();
      hTime->Fill(time);
    }
  }

  t.add_canvas("time",1200,600);
  hTime->Draw();
  t.save_canvas("data/draw_time", 0);
}
