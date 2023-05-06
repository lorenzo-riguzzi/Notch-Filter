void SweepResistance()
{
    TGraph *g1 = new TGraph("SweepResistance1.dat");
    TGraph *g2 = new TGraph("SweepResistance2.dat");
    TGraph *g3 = new TGraph("SweepResistance3.dat");

    g1->SetMarkerStyle(kOpenCircle);
    g1->SetMarkerColor(kBlue);
    g1->SetLineColor(kBlue);
    g1->SetTitle("Voltage on different resistors");
    g1->GetXaxis()->SetTitle("Frequency (Hz)");
    g1->GetYaxis()->SetTitle("Amplitude (V)");
    /*g1->GetXaxis()->SetLimits(1000, 2500);
    g1->GetHistogram()->SetMaximum(2.5);
    g1->GetHistogram()->SetMinimum(2.4);*/

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

    ifstream in1;
    in1.open("SweepResistance1.dat");
    Double_t v01{5};
    Double_t f01{};
    Float_t x1, y1;
    while (in1.good())
    {
        in1 >> x1 >> y1;
        if (y1 < v01)
        {
            v01 = y1;
            f01 = x1;

        }
    }
    in1.close();

    ifstream in2;
    in2.open("SweepResistance2.dat");
    Double_t v02{5};
    Double_t f02{};
    Float_t x2, y2;
    while (in2.good())
    {
        in2 >> x2 >> y2;
        if (y2 < v02)
        {
            v02 = y2;
            f02 = x2;

        }
    }
    in2.close();

    ifstream in3;
    in3.open("SweepResistance3.dat");
    Double_t v03{5};
    Double_t f03{};
    Float_t x3, y3;
    while (in3.good())
    {
        in3 >> x3 >> y3;
        if (y3 < v03)
        {
            v03 = y3;
            f03 = x3;

        }
    }
    in3.close();

   cout << endl;
   cout << "Min Voltage on R1: " << v01 << endl;
   cout << "Resonance Frequency on R1: " << f01 << endl;
   cout << endl;
   cout << "Min Voltage on R2: " << v02 << endl;
   cout << "Resonance Frequency on R2: " << f02 << endl;
   cout << endl;
   cout << "Min Voltage on R3: " << v03 << endl;
   cout << "Resonance Frequency on R3: " << f03 << endl;
}