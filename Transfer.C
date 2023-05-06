void Transfer(){
    TGraph *g1 = new TGraph("TransferIn.dat");
    TGraph *g2 = new TGraph("TransferR.dat");
    TGraphErrors *h = new TGraphErrors(); 
    h->SetMarkerStyle(kOpenCircle);
    h->SetMarkerColor(kBlue);
    h->SetLineColor(kBlue);
    h->SetTitle("H(#omega)");
    h->GetXaxis()->SetTitle("Frequency (Hz)");
    h->GetYaxis()->SetTitle("V_{R}/V_{In}");

    Int_t min = TMath::Min(g1->GetN(), g2->GetN());
    Double_t dy = 0.01;

    for(Int_t i{}; i < min; i++){
        Double_t y = g2->GetPointY(i)/g1->GetPointY(i);
        Double_t w = (g1->GetPointX(i) + g2->GetPointX(i))/2;
        Double_t dw = (g1->GetPointX(i) - g2->GetPointX(i))/2;
        h->AddPoint(w, y);
        h->SetPointError(i, dw, dy);
    }

    TCanvas *c = new TCanvas();

    h->Draw("ALP");
}