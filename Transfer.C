#include "TMath.h"

Double_t myFunction(Double_t *x, Double_t *par)
{
    Double_t xx = x[0];
    Double_t z = 2 * TMath::Pi() * xx;
    /*par[0]=L
    par[1]=C
    par[2]=r
    par[3]=R*/
    Double_t A = 1 - z * z * par[0] * par[1];
    Double_t B = z * par[1] * par[2];
    Double_t D = par[2] + (par[3] + 50) * A;
    Double_t E = z * (par[0] + par[1] * (par[3] + 50) * par[2]);

    Double_t val = par[3] / (D * D + E * E) * TMath::Sqrt((A * D + B * E) * (A * D + B * E) + (B * D - A * E) * (B * D - A * E));
    return val;
}

void Transfer()
{
    TGraph *g1 = new TGraph("TransferIn1.dat");
    TGraph *r1 = new TGraph("TransferR1.dat");
    TGraphErrors *h1 = new TGraphErrors();
    TF1 *f1 = new TF1("f1", myFunction, 0, 20000, 4);
    h1->SetMarkerStyle(kOpenCircle);
    h1->SetMarkerColor(kBlue);
    h1->SetLineColor(kBlue);

    Int_t min1 = TMath::Min(g1->GetN(), r1->GetN());

    for (Int_t i{}; i < min1; i++)
    {
        Double_t y = r1->GetPointY(i) / g1->GetPointY(i);
        Double_t w = (g1->GetPointX(i) + r1->GetPointX(i)) / 2;
        // Double_t dw = (g1->GetPointX(i) - f1->GetPointX(i)) / 2;
        Double_t dw = 0.186;
        Double_t dy = (y + 1) * 0.002 / g1->GetPointY(i);
        h1->AddPoint(w, y);
        h1->SetPointError(i, dw, dy);
    }

    TGraph *g2 = new TGraph("TransferIn2.dat");
    TGraph *r2 = new TGraph("TransferR2.dat");
    TGraphErrors *h2 = new TGraphErrors();
    TF1 *f2 = new TF1("f2", myFunction, 0, 20000, 4);
    h2->SetMarkerStyle(kOpenCircle);
    h2->SetMarkerColor(kGreen);
    h2->SetLineColor(kGreen);
    h2->SetTitle("H(#omega)");
    h2->GetXaxis()->SetTitle("Frequency (Hz)");
    h2->GetYaxis()->SetTitle("V_{R}/V_{In}");
    h2->GetYaxis()->SetRangeUser(0, 1.02);

    Int_t min2 = TMath::Min(g2->GetN(), r2->GetN());

    for (Int_t i{}; i < min2; i++)
    {
        Double_t y = r2->GetPointY(i) / g2->GetPointY(i);
        Double_t w = (g2->GetPointX(i) + r2->GetPointX(i)) / 2;
        // Double_t dw = (g1->GetPointX(i) - f1->GetPointX(i)) / 2;
        Double_t dw = 0.186;
        Double_t dy = (y + 1) * 0.002 / g2->GetPointY(i);
        h2->AddPoint(w, y);
        h2->SetPointError(i, dw, dy);
    }

    /*TGraph *g3 = new TGraph("TransferIn3.dat");
    TGraph *f3 = new TGraph("TransferR3.dat");
    TGraphErrors *h3 = new TGraphErrors();
    TF1 *r3 = new TF1("r3", myFunction, 0, 20000, 4);
    h3->SetMarkerStyle(kOpenCircle);
    h3->SetMarkerColor(kRed);
    h3->SetLineColor(kRed);

    Int_t min3 = TMath::Min(g3->GetN(), r3->GetN());

    for (Int_t i{}; i < min3; i++)
    {
        Double_t y = r3->GetPointY(i) / g3->GetPointY(i);
        Double_t w = (g3->GetPointX(i) + r3->GetPointX(i)) / 2;
        // Double_t dw = (g1->GetPointX(i) - f1->GetPointX(i)) / 2;
        Double_t dw = 0.186;
        Double_t dy = (y + 1) * 0.002 / g3->GetPointY(i);
        h3->AddPoint(w, y);
        h3->SetPointError(i, dw, dy);
    }*/

    TCanvas *c = new TCanvas();
    
    f2->SetParameter(0, 0.01014);
    f2->SetParameter(1, 20.88 * TMath::Power(10, -9));
    f2->SetParameter(2, 37.937);
    f2->SetParameter(3, 680);

    h2->Draw("ALP");
    h2->Fit("f2");

    
    f1->SetParameter(0, 0.01014);
    f1->SetParameter(1, 20.88 * TMath::Power(10, -9));
    f1->SetParameter(2, 37.937);
    f1->SetParameter(3, 10000);

    h1->Draw("LP, SAME");
    h1->Fit("f1");
    // f->Draw("SAME");
    
    
    /*f3->SetParameter(0, 0.01014);
    f3->SetParameter(1, 20.88 * TMath::Power(10, -9));
    f3->SetParameter(2, 37.937);
    f3->SetParameter(3, 680);

    h3->Draw("LP, SAME");
    h3->Fit("f3");*/

    cout << endl;
    cout << "------PARAMETERS FOR R1------" << endl;
    cout << "L = " << f1->GetParameter(0) << " +/- " << f1->GetParError(0) << endl;
    cout << "C = " << f1->GetParameter(1) << " +/- " << f1->GetParError(1) << endl;
    cout << "R(L) = " << f1->GetParameter(2) << " +/- " << f1->GetParError(2) << endl;
    cout << "R = " << f1->GetParameter(3) << " +/- " << f1->GetParError(3) << endl;
    cout << endl;
    cout << "x^2 = " << f1->GetChisquare() << endl;
    cout << "dof = " << f1->GetNDF() << endl;
    cout << "X^2/Ndof = " << f1->GetChisquare() / f1->GetNDF() << endl;
    cout << endl;
    cout << "v0 = " << f1->GetMinimumX(0, 20000) << endl;
    cout << endl;

    cout << endl;
    cout << "------PARAMETERS FOR R2------" << endl;
    cout << "L = " << f2->GetParameter(0) << " +/- " << f2->GetParError(0) << endl;
    cout << "C = " << f2->GetParameter(1) << " +/- " << f2->GetParError(1) << endl;
    cout << "R(L) = " << f2->GetParameter(2) << " +/- " << f2->GetParError(2) << endl;
    cout << "R = " << f2->GetParameter(3) << " +/- " << f2->GetParError(3) << endl;
    cout << endl;
    cout << "x^2 = " << f2->GetChisquare() << endl;
    cout << "dof = " << f2->GetNDF() << endl;
    cout << "X^2/Ndof = " << f2->GetChisquare() / f2->GetNDF() << endl;
    cout << endl;
    cout << "v0 = " << f2->GetMinimumX(0, 20000) << endl;
    cout << endl;
}