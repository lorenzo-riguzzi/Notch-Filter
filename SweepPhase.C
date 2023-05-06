void SweepPhase()
{
    TGraph *g = new TGraph("SweepPhase1.dat");

    g->SetMarkerStyle(kOpenCircle);
    g->SetMarkerColor(kBlue);
    g->SetLineColor(kBlue);
    g->SetTitle("Phase");
    g->GetXaxis()->SetTitle("Frequency (Hz)");
    g->GetYaxis()->SetTitle("Phase)");

    TCanvas *c = new TCanvas();
    g->Draw("ALP");
}