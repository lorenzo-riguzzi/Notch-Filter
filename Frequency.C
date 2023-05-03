void Frequency()
{
    TGraph *g1 = new TGraph("Frequency1.dat");
    TGraph *g2 = new TGraph("Frequency2.dat");
    TGraph *g3 = new TGraph("Frequency3.dat");

    g1->SetMarkerStyle(kOpenCircle);
    g1->SetMarkerColor(kBlue);
    g1->SetLineColor(kBlue);
    g1->SetTitle("Voltage on different resistors");
    g1->GetXaxis()->SetTitle("Frequency (Hz)");
    g1->GetYaxis()->SetTitle("Amplitude (V)");
    g1->GetXaxis()->SetLimits(1000, 2500);
    g1->GetHistogram()->SetMaximum(2.5);
    g1->GetHistogram()->SetMinimum(2.4);

    g2->SetMarkerStyle(kOpenCircle);
    g2->SetMarkerColor(kGreen);
    g2->SetLineColor(kGreen);

    g3->SetMarkerStyle(kOpenCircle);
    g3->SetMarkerColor(kRed);
    g3->SetLineColor(kRed);

    TLegend *l = new TLegend();

    l->AddEntry(g1, "V_{R1}");
    l->AddEntry(g2, "V_{R2}");
    l->AddEntry(g3, "V_{R3}");

    TCanvas *c = new TCanvas();
    g1->Draw("ALP");
    g2->Draw("LP SAME");
    g3->Draw("LP SAME");
    l->Draw("SAME");

    double f01 = TMath::MinElement(g1->GetN(), g1->GetX());
    double f02 = TMath::MinElement(g2->GetN(), g2->GetX());
    double f03 = TMath::MinElement(g3->GetN(), g3->GetX());

    cout << "Resonance frequency for R1: " << f01 << endl;
    cout << "Resonance frequency for R2: " << f02 << endl;
    cout << "Resonance frequency for R3: " << f03 << endl;
}