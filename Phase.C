void GausFit2kHz()
{
    gStyle->SetOptStat(2210);
    gStyle->SetOptFit(111);

    ifstream in1;
    in1.open("Phase2kHz.dat");
    double y_max = -100;
    double x_max = 0;
    double y_min{100};
    double x_min{15000};
    Float_t x1, y1;
    while (in1.good())
    {
        in1 >> x1 >> y1;
        if (y1 > y_max)
        {
            y_max = y1;
        }
        if (y1 < y_min)
        {
            y_min = y1;
        }
        if (x1 > x_max)
        {
            x_max = x1;
        }
        if (x1 < x_min)
        {
            x_min = x1;
        }
    }
    in1.close();

    cout << "y_min: " << y_min << endl;
    cout << "y_max: " << y_max << endl;
    cout << "x_min: " << x_min << endl;
    cout << "x_max: " << x_max << endl;

    TH1F *h1 = new TH1F("h1", "Fase", 100, y_min - 0.001, y_max + 0.001);
    TF1 *f1 = new TF1("f1", "gaus", y_min - 0.001, y_max + 0.001);

    TH1F *h2 = new TH1F("h2", "Frequenza", 50, x_min - 0.01, x_max + 0.01);
    TF1 *f2 = new TF1("f2", "gaus", x_min - 0.01, x_max + 0.01);

    ifstream in2;
    in2.open("Phase2kHz.dat");
    Float_t x, y;
    while (1)
    {
        in2 >> x >> y;
        if (!in2.good())
            break;
        h1->Fill(y);
        h2->Fill(x);
    }
    in2.close();

    TCanvas *c1 = new TCanvas();
    h1->GetXaxis()->SetTitle("Voltage (mV)");
    h1->GetYaxis()->SetTitle("Counts");
    h1->SetFillColor(kBlue); //(KBlue=2)
    h1->SetMarkerStyle(4);   // Open Circle // altrimenti kOpenCircle
    h1->SetLineWidth(2);     // spessore linea
    h1->Draw("HISTO");
    h1->Fit("f1");
    f1->Draw("SAME");

    TCanvas *c2 = new TCanvas();
    h2->GetXaxis()->SetTitle("Voltage (mV)");
    h2->GetYaxis()->SetTitle("Counts");
    h2->SetFillColor(kBlue); //(KBlue=2)
    h2->SetMarkerStyle(4);   // Open Circle // altrimenti kOpenCircle
    h2->SetLineWidth(2);     // spessore linea
    h2->Draw("HISTO");
    h2->Fit("f2");
    f2->Draw("SAME");

    cout << endl;
    cout << "Voltage: " << endl;
    cout << "Mean: " << f1->GetParameter(1) << " +/- " << f1->GetParError(1) << endl;
    cout << "Std. Dev.: " << f1->GetParameter(2) << " +/- " << f1->GetParError(2) << endl;
    cout << endl;

    cout << "Frequency: " << endl; 
    cout << "Mean: " << f2->GetParameter(1) << " +/- " << f2->GetParError(1) << endl;
    cout << "Std. Dev.: " << f2->GetParameter(2) << " +/- " << f2->GetParError(2) << endl;
    cout << endl;
}

void GausFit5kHz()
{
    gStyle->SetOptStat(2210);
    gStyle->SetOptFit(111);

    ifstream in1;
    in1.open("Phase5kHz.dat");
    double y_max = -100;
    double x_max = 0;
    double y_min{100};
    double x_min{15000};
    Float_t x1, y1;
    while (in1.good())
    {
        in1 >> x1 >> y1;
        if (y1 > y_max)
        {
            y_max = y1;
        }
        if (y1 < y_min)
        {
            y_min = y1;
        }
        if (x1 > x_max)
        {
            x_max = x1;
        }
        if (x1 < x_min)
        {
            x_min = x1;
        }
    }
    in1.close();

    cout << "y_min: " << y_min << endl;
    cout << "y_max: " << y_max << endl;
    cout << "x_min: " << x_min << endl;
    cout << "x_max: " << x_max << endl;

    TH1F *h1 = new TH1F("h1", "Fase", 100, y_min - 0.001, y_max + 0.001);
    TF1 *f1 = new TF1("f1", "gaus", y_min - 0.001, y_max + 0.001);

    TH1F *h2 = new TH1F("h2", "Frequenza", 50, x_min - 0.01, x_max + 0.01);
    TF1 *f2 = new TF1("f2", "gaus", x_min - 0.01, x_max + 0.01);

    ifstream in2;
    in2.open("Phase5kHz.dat");
    Float_t x, y;
    while (1)
    {
        in2 >> x >> y;
        if (!in2.good())
            break;
        h1->Fill(y);
        h2->Fill(x);
    }
    in2.close();

    TCanvas *c1 = new TCanvas();
    h1->GetXaxis()->SetTitle("Voltage (mV)");
    h1->GetYaxis()->SetTitle("Counts");
    h1->SetFillColor(kBlue); //(KBlue=2)
    h1->SetMarkerStyle(4);   // Open Circle // altrimenti kOpenCircle
    h1->SetLineWidth(2);     // spessore linea
    h1->Draw("HISTO");
    h1->Fit("f1");
    f1->Draw("SAME");

    TCanvas *c2 = new TCanvas();
    h2->GetXaxis()->SetTitle("Voltage (mV)");
    h2->GetYaxis()->SetTitle("Counts");
    h2->SetFillColor(kBlue); //(KBlue=2)
    h2->SetMarkerStyle(4);   // Open Circle // altrimenti kOpenCircle
    h2->SetLineWidth(2);     // spessore linea
    h2->Draw("HISTO");
    h2->Fit("f2");
    f2->Draw("SAME");

    cout << endl;
    cout << "Voltage: " << endl;
    cout << "Mean: " << f1->GetParameter(1) << " +/- " << f1->GetParError(1) << endl;
    cout << "Std. Dev.: " << f1->GetParameter(2) << " +/- " << f1->GetParError(2) << endl;
    cout << endl;

    cout << "Frequency: " << endl; 
    cout << "Mean: " << f2->GetParameter(1) << " +/- " << f2->GetParError(1) << endl;
    cout << "Std. Dev.: " << f2->GetParameter(2) << " +/- " << f2->GetParError(2) << endl;
    cout << endl;
}

void GausFit6kHz()
{
    gStyle->SetOptStat(2210);
    gStyle->SetOptFit(111);

    ifstream in1;
    in1.open("Phase6kHz.dat");
    double y_max = -100;
    double x_max = 0;
    double y_min{100};
    double x_min{15000};
    Float_t x1, y1;
    while (in1.good())
    {
        in1 >> x1 >> y1;
        if (y1 > y_max)
        {
            y_max = y1;
        }
        if (y1 < y_min)
        {
            y_min = y1;
        }
        if (x1 > x_max)
        {
            x_max = x1;
        }
        if (x1 < x_min)
        {
            x_min = x1;
        }
    }
    in1.close();

    cout << "y_min: " << y_min << endl;
    cout << "y_max: " << y_max << endl;
    cout << "x_min: " << x_min << endl;
    cout << "x_max: " << x_max << endl;

    TH1F *h1 = new TH1F("h1", "Fase", 100, y_min - 0.001, y_max + 0.001);
    TF1 *f1 = new TF1("f1", "gaus", y_min - 0.001, y_max + 0.001);

    TH1F *h2 = new TH1F("h2", "Frequenza", 50, x_min - 0.01, x_max + 0.01);
    TF1 *f2 = new TF1("f2", "gaus", x_min - 0.01, x_max + 0.01);

    ifstream in2;
    in2.open("Phase6kHz.dat");
    Float_t x, y;
    while (1)
    {
        in2 >> x >> y;
        if (!in2.good())
            break;
        h1->Fill(y);
        h2->Fill(x);
    }
    in2.close();

    TCanvas *c1 = new TCanvas();
    h1->GetXaxis()->SetTitle("Voltage (mV)");
    h1->GetYaxis()->SetTitle("Counts");
    h1->SetFillColor(kBlue); //(KBlue=2)
    h1->SetMarkerStyle(4);   // Open Circle // altrimenti kOpenCircle
    h1->SetLineWidth(2);     // spessore linea
    h1->Draw("HISTO");
    h1->Fit("f1");
    f1->Draw("SAME");

    TCanvas *c2 = new TCanvas();
    h2->GetXaxis()->SetTitle("Voltage (mV)");
    h2->GetYaxis()->SetTitle("Counts");
    h2->SetFillColor(kBlue); //(KBlue=2)
    h2->SetMarkerStyle(4);   // Open Circle // altrimenti kOpenCircle
    h2->SetLineWidth(2);     // spessore linea
    h2->Draw("HISTO");
    h2->Fit("f2");
    f2->Draw("SAME");

    cout << endl;
    cout << "Voltage: " << endl;
    cout << "Mean: " << f1->GetParameter(1) << " +/- " << f1->GetParError(1) << endl;
    cout << "Std. Dev.: " << f1->GetParameter(2) << " +/- " << f1->GetParError(2) << endl;
    cout << endl;

    cout << "Frequency: " << endl; 
    cout << "Mean: " << f2->GetParameter(1) << " +/- " << f2->GetParError(1) << endl;
    cout << "Std. Dev.: " << f2->GetParameter(2) << " +/- " << f2->GetParError(2) << endl;
    cout << endl;
}

void GausFit9kHz()
{
    gStyle->SetOptStat(2210);
    gStyle->SetOptFit(111);

    ifstream in1;
    in1.open("Phase9kHz.dat");
    double y_max = -100;
    double x_max = 0;
    double y_min{100};
    double x_min{15000};
    Float_t x1, y1;
    while (in1.good())
    {
        in1 >> x1 >> y1;
        if (y1 > y_max)
        {
            y_max = y1;
        }
        if (y1 < y_min)
        {
            y_min = y1;
        }
        if (x1 > x_max)
        {
            x_max = x1;
        }
        if (x1 < x_min)
        {
            x_min = x1;
        }
    }
    in1.close();

    cout << "y_min: " << y_min << endl;
    cout << "y_max: " << y_max << endl;
    cout << "x_min: " << x_min << endl;
    cout << "x_max: " << x_max << endl;

    TH1F *h1 = new TH1F("h1", "Fase", 100, y_min - 0.001, y_max + 0.001);
    TF1 *f1 = new TF1("f1", "gaus", y_min - 0.001, y_max + 0.001);

    TH1F *h2 = new TH1F("h2", "Frequenza", 50, x_min - 0.01, x_max + 0.01);
    TF1 *f2 = new TF1("f2", "gaus", x_min - 0.01, x_max + 0.01);

    ifstream in2;
    in2.open("Phase9kHz.dat");
    Float_t x, y;
    while (1)
    {
        in2 >> x >> y;
        if (!in2.good())
            break;
        h1->Fill(y);
        h2->Fill(x);
    }
    in2.close();

    TCanvas *c1 = new TCanvas();
    h1->GetXaxis()->SetTitle("Voltage (mV)");
    h1->GetYaxis()->SetTitle("Counts");
    h1->SetFillColor(kBlue); //(KBlue=2)
    h1->SetMarkerStyle(4);   // Open Circle // altrimenti kOpenCircle
    h1->SetLineWidth(2);     // spessore linea
    h1->Draw("HISTO");
    h1->Fit("f1");
    f1->Draw("SAME");

    TCanvas *c2 = new TCanvas();
    h2->GetXaxis()->SetTitle("Voltage (mV)");
    h2->GetYaxis()->SetTitle("Counts");
    h2->SetFillColor(kBlue); //(KBlue=2)
    h2->SetMarkerStyle(4);   // Open Circle // altrimenti kOpenCircle
    h2->SetLineWidth(2);     // spessore linea
    h2->Draw("HISTO");
    h2->Fit("f2");
    f2->Draw("SAME");

    cout << endl;
    cout << "Voltage: " << endl;
    cout << "Mean: " << f1->GetParameter(1) << " +/- " << f1->GetParError(1) << endl;
    cout << "Std. Dev.: " << f1->GetParameter(2) << " +/- " << f1->GetParError(2) << endl;
    cout << endl;

    cout << "Frequency: " << endl; 
    cout << "Mean: " << f2->GetParameter(1) << " +/- " << f2->GetParError(1) << endl;
    cout << "Std. Dev.: " << f2->GetParameter(2) << " +/- " << f2->GetParError(2) << endl;
    cout << endl;
}

void GausFit13kHz()
{
    gStyle->SetOptStat(2210);
    gStyle->SetOptFit(111);

    ifstream in1;
    in1.open("Phase13kHz.dat");
    double y_max = -100;
    double x_max = 0;
    double y_min{100};
    double x_min{15000};
    Float_t x1, y1;
    while (in1.good())
    {
        in1 >> x1 >> y1;
        if (y1 > y_max)
        {
            y_max = y1;
        }
        if (y1 < y_min)
        {
            y_min = y1;
        }
        if (x1 > x_max)
        {
            x_max = x1;
        }
        if (x1 < x_min)
        {
            x_min = x1;
        }
    }
    in1.close();

    cout << "y_min: " << y_min << endl;
    cout << "y_max: " << y_max << endl;
    cout << "x_min: " << x_min << endl;
    cout << "x_max: " << x_max << endl;

    TH1F *h1 = new TH1F("h1", "Fase", 100, y_min - 0.001, y_max + 0.001);
    TF1 *f1 = new TF1("f1", "gaus", y_min - 0.001, y_max + 0.001);

    TH1F *h2 = new TH1F("h2", "Frequenza", 50, x_min - 0.01, x_max + 0.01);
    TF1 *f2 = new TF1("f2", "gaus", x_min - 0.01, x_max + 0.01);

    ifstream in2;
    in2.open("Phase13kHz.dat");
    Float_t x, y;
    while (1)
    {
        in2 >> x >> y;
        if (!in2.good())
            break;
        h1->Fill(y);
        h2->Fill(x);
    }
    in2.close();

    TCanvas *c1 = new TCanvas();
    h1->GetXaxis()->SetTitle("Voltage (mV)");
    h1->GetYaxis()->SetTitle("Counts");
    h1->SetFillColor(kBlue); //(KBlue=2)
    h1->SetMarkerStyle(4);   // Open Circle // altrimenti kOpenCircle
    h1->SetLineWidth(2);     // spessore linea
    h1->Draw("HISTO");
    h1->Fit("f1");
    f1->Draw("SAME");

    TCanvas *c2 = new TCanvas();
    h2->GetXaxis()->SetTitle("Voltage (mV)");
    h2->GetYaxis()->SetTitle("Counts");
    h2->SetFillColor(kBlue); //(KBlue=2)
    h2->SetMarkerStyle(4);   // Open Circle // altrimenti kOpenCircle
    h2->SetLineWidth(2);     // spessore linea
    h2->Draw("HISTO");
    h2->Fit("f2");
    f2->Draw("SAME");

    cout << endl;
    cout << "Voltage: " << endl;
    cout << "Mean: " << f1->GetParameter(1) << " +/- " << f1->GetParError(1) << endl;
    cout << "Std. Dev.: " << f1->GetParameter(2) << " +/- " << f1->GetParError(2) << endl;
    cout << endl;

    cout << "Frequency: " << endl; 
    cout << "Mean: " << f2->GetParameter(1) << " +/- " << f2->GetParError(1) << endl;
    cout << "Std. Dev.: " << f2->GetParameter(2) << " +/- " << f2->GetParError(2) << endl;
    cout << endl;
}