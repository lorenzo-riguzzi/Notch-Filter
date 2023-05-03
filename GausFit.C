void GausFit()
{
    gStyle->SetOptStat(2210);
    gStyle->SetOptFit(111);

    TH1F *h = new TH1F("2", "Voltaggio FGen", 100, 0, 10);
    TF1 *f = new TF1("f", "gaus", 0, 10);

    ifstream in;
    in.open("GausFit.dat");
    Float_t x, y;
    while (1)
    {
        in >> x >> y;
        if (!in.good())
            break;
        h->Fill(y);
    }
    in.close();

    TCanvas *c = new TCanvas();
    h->GetXaxis()->SetTitle("Amplitude (V)");
    h->GetYaxis()->SetTitle("Counts");
    h->SetFillColor(kBlue);   //(KBlue=2)
    h->SetMarkerStyle(4);     // Open Circle // altrimenti kOpenCircle
    h->SetLineWidth(2);       // spessore linea
    h->Draw("HISTO");
    h->Fit("f", "R");
    f->Draw("SAME");

    cout << "Mean: " << f->GetParameter(1) << " +/- " << f->GetParError(1) << endl;
    cout << "Std. Dev.: " << f->GetParameter(2) << " +/- " << f->GetParError(2) << endl;

    c->Print("GausFit.pdf", "pdf");
}