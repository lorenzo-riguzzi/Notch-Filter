void Scatter2kHz()
{
    gStyle->SetOptStat(2210);

    ifstream in1;
    in1.open("Resistance2kHz.dat");
    double y_max = 0;
    double x_max = 0;
    double y_min{5};
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

    ifstream in2;
    in2.open("Phase2kHz.dat");
    double p_max = -100;
    double f_max = 0;
    double p_min{100};
    double f_min{15000};
    Float_t f1, p1;
    while (in2.good())
    {
        in2 >> f1 >> p1;
        if (p1 > p_max)
        {
            p_max = p1;
        }
        if (p1 < p_min)
        {
            p_min = p1;
        }
        if (f1 > f_max)
        {
            f_max = f1;
        }
        if (f1 < f_min)
        {
            f_min = f1;
        }
    }
    in2.close();

    TH2F *h1 = new TH2F("h1", "", 100, x_min - 0.01, x_max + 0.01, 100, y_min - 0.001, y_max + 0.001);
    TH2F *h2 = new TH2F("h2", "", 100, f_min - 0.01, f_max + 0.01, 100, p_min - 0.001, p_max + 0.001);

    ifstream in3;
    in3.open("Resistance2kHz.dat");
    Float_t x, y;
    while (1)
    {
        in3 >> x >> y;
        if (!in3.good())
            break;
        h1->Fill(x, y);
    }
    in3.close();

    ifstream in4;
    in4.open("Phase2kHz.dat");
    Float_t f, p;
    while (1)
    {
        in4 >> f >> p;
        if (!in4.good())
            break;
        h2->Fill(f, p);
    }
    in4.close();

    h1->GetXaxis()->SetTitle("Frequency (Hz)");
    h1->GetYaxis()->SetTitle("Voltage (V)");
    h1->GetZaxis()->SetTitle("Counts");
    h2->GetXaxis()->SetTitle("Frequency (Hz)");
    h2->GetYaxis()->SetTitle("Phase");
    h2->GetZaxis()->SetTitle("Counts");

    TCanvas *c = new TCanvas();
    c->Divide(2, 2);
    c->cd(1);
    h1->Draw("COLZ");
    c->cd(2);
    h1->Draw("LEGO2Z");
    c->cd(3);
    h2->Draw("COLZ");
    c->cd(4);
    h2->Draw("LEGO2Z");
}

void Scatter5kHz()
{
    gStyle->SetOptStat(2210);

    ifstream in1;
    in1.open("Resistance5kHz.dat");
    double y_max = 0;
    double x_max = 0;
    double y_min{5};
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

    ifstream in2;
    in2.open("Phase5kHz.dat");
    double p_max = -100;
    double f_max = 0;
    double p_min{100};
    double f_min{15000};
    Float_t f1, p1;
    while (in2.good())
    {
        in2 >> f1 >> p1;
        if (p1 > p_max)
        {
            p_max = p1;
        }
        if (p1 < p_min)
        {
            p_min = p1;
        }
        if (f1 > f_max)
        {
            f_max = f1;
        }
        if (f1 < f_min)
        {
            f_min = f1;
        }
    }
    in2.close();

    TH2F *h1 = new TH2F("h1", "", 100, x_min - 0.01, x_max + 0.01, 100, y_min - 0.001, y_max + 0.001);
    TH2F *h2 = new TH2F("h2", "", 100, f_min - 0.01, f_max + 0.01, 100, p_min - 0.001, p_max + 0.001);

    ifstream in3;
    in3.open("Resistance5kHz.dat");
    Float_t x, y;
    while (1)
    {
        in3 >> x >> y;
        if (!in3.good())
            break;
        h1->Fill(x, y);
    }
    in3.close();

    ifstream in4;
    in4.open("Phase5kHz.dat");
    Float_t f, p;
    while (1)
    {
        in4 >> f >> p;
        if (!in4.good())
            break;
        h2->Fill(f, p);
    }
    in4.close();

    h1->GetXaxis()->SetTitle("Frequency (Hz)");
    h1->GetYaxis()->SetTitle("Voltage (V)");
    h1->GetZaxis()->SetTitle("Counts");
    h2->GetXaxis()->SetTitle("Frequency (Hz)");
    h2->GetYaxis()->SetTitle("Phase");
    h2->GetZaxis()->SetTitle("Counts");

    TCanvas *c = new TCanvas();
    c->Divide(2, 2);
    c->cd(1);
    h1->Draw("COLZ");
    c->cd(2);
    h1->Draw("LEGO2Z");
    c->cd(3);
    h2->Draw("COLZ");
    c->cd(4);
    h2->Draw("LEGO2Z");
}

void Scatter6kHz()
{
    gStyle->SetOptStat(2210);

    ifstream in1;
    in1.open("Resistance6kHz.dat");
    double y_max = 0;
    double x_max = 0;
    double y_min{5};
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

    ifstream in2;
    in2.open("Phase6kHz.dat");
    double p_max = -100;
    double f_max = 0;
    double p_min{100};
    double f_min{15000};
    Float_t f1, p1;
    while (in2.good())
    {
        in2 >> f1 >> p1;
        if (p1 > p_max)
        {
            p_max = p1;
        }
        if (p1 < p_min)
        {
            p_min = p1;
        }
        if (f1 > f_max)
        {
            f_max = f1;
        }
        if (f1 < f_min)
        {
            f_min = f1;
        }
    }
    in2.close();

    TH2F *h1 = new TH2F("h1", "", 100, x_min - 0.01, x_max + 0.01, 100, y_min - 0.001, y_max + 0.001);
    TH2F *h2 = new TH2F("h2", "", 100, f_min - 0.01, f_max + 0.01, 100, p_min - 0.001, p_max + 0.001);

    ifstream in3;
    in3.open("Resistance6kHz.dat");
    Float_t x, y;
    while (1)
    {
        in3 >> x >> y;
        if (!in3.good())
            break;
        h1->Fill(x, y);
    }
    in3.close();

    ifstream in4;
    in4.open("Phase6kHz.dat");
    Float_t f, p;
    while (1)
    {
        in4 >> f >> p;
        if (!in4.good())
            break;
        h2->Fill(f, p);
    }
    in4.close();

    h1->GetXaxis()->SetTitle("Frequency (Hz)");
    h1->GetYaxis()->SetTitle("Voltage (V)");
    h1->GetZaxis()->SetTitle("Counts");
    h2->GetXaxis()->SetTitle("Frequency (Hz)");
    h2->GetYaxis()->SetTitle("Phase");
    h2->GetZaxis()->SetTitle("Counts");

    TCanvas *c = new TCanvas();
    c->Divide(2, 2);
    c->cd(1);
    h1->Draw("COLZ");
    c->cd(2);
    h1->Draw("LEGO2Z");
    c->cd(3);
    h2->Draw("COLZ");
    c->cd(4);
    h2->Draw("LEGO2Z");
}

void Scatter9kHz()
{
    gStyle->SetOptStat(2210);

    ifstream in1;
    in1.open("Resistance9kHz.dat");
    double y_max = 0;
    double x_max = 0;
    double y_min{5};
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

    ifstream in2;
    in2.open("Phase9kHz.dat");
    double p_max = -100;
    double f_max = 0;
    double p_min{100};
    double f_min{15000};
    Float_t f1, p1;
    while (in2.good())
    {
        in2 >> f1 >> p1;
        if (p1 > p_max)
        {
            p_max = p1;
        }
        if (p1 < p_min)
        {
            p_min = p1;
        }
        if (f1 > f_max)
        {
            f_max = f1;
        }
        if (f1 < f_min)
        {
            f_min = f1;
        }
    }
    in2.close();

    TH2F *h1 = new TH2F("h1", "", 100, x_min - 0.01, x_max + 0.01, 100, y_min - 0.001, y_max + 0.001);
    TH2F *h2 = new TH2F("h2", "", 100, f_min - 0.01, f_max + 0.01, 100, p_min - 0.001, p_max + 0.001);

    ifstream in3;
    in3.open("Resistance9kHz.dat");
    Float_t x, y;
    while (1)
    {
        in3 >> x >> y;
        if (!in3.good())
            break;
        h1->Fill(x, y);
    }
    in3.close();

    ifstream in4;
    in4.open("Phase9kHz.dat");
    Float_t f, p;
    while (1)
    {
        in4 >> f >> p;
        if (!in4.good())
            break;
        h2->Fill(f, p);
    }
    in4.close();

    h1->GetXaxis()->SetTitle("Frequency (Hz)");
    h1->GetYaxis()->SetTitle("Voltage (V)");
    h1->GetZaxis()->SetTitle("Counts");
    h2->GetXaxis()->SetTitle("Frequency (Hz)");
    h2->GetYaxis()->SetTitle("Phase");
    h2->GetZaxis()->SetTitle("Counts");

    TCanvas *c = new TCanvas();
    c->Divide(2, 2);
    c->cd(1);
    h1->Draw("COLZ");
    c->cd(2);
    h1->Draw("LEGO2Z");
    c->cd(3);
    h2->Draw("COLZ");
    c->cd(4);
    h2->Draw("LEGO2Z");
}

void Scatter13kHz()
{
    gStyle->SetOptStat(2210);

    ifstream in1;
    in1.open("Resistance13kHz.dat");
    double y_max = 0;
    double x_max = 0;
    double y_min{5};
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

    ifstream in2;
    in2.open("Phase13kHz.dat");
    double p_max = -100;
    double f_max = 0;
    double p_min{100};
    double f_min{15000};
    Float_t f1, p1;
    while (in2.good())
    {
        in2 >> f1 >> p1;
        if (p1 > p_max)
        {
            p_max = p1;
        }
        if (p1 < p_min)
        {
            p_min = p1;
        }
        if (f1 > f_max)
        {
            f_max = f1;
        }
        if (f1 < f_min)
        {
            f_min = f1;
        }
    }
    in2.close();

    TH2F *h1 = new TH2F("h1", "", 100, x_min - 0.01, x_max + 0.01, 100, y_min - 0.001, y_max + 0.001);
    TH2F *h2 = new TH2F("h2", "", 100, f_min - 0.01, f_max + 0.01, 100, p_min - 0.001, p_max + 0.001);

    ifstream in3;
    in3.open("Resistance13kHz.dat");
    Float_t x, y;
    while (1)
    {
        in3 >> x >> y;
        if (!in3.good())
            break;
        h1->Fill(x, y);
    }
    in3.close();

    ifstream in4;
    in4.open("Phase13kHz.dat");
    Float_t f, p;
    while (1)
    {
        in4 >> f >> p;
        if (!in4.good())
            break;
        h2->Fill(f, p);
    }
    in4.close();

    h1->GetXaxis()->SetTitle("Frequency (Hz)");
    h1->GetYaxis()->SetTitle("Voltage (V)");
    h1->GetZaxis()->SetTitle("Counts");
    h2->GetXaxis()->SetTitle("Frequency (Hz)");
    h2->GetYaxis()->SetTitle("Phase");
    h2->GetZaxis()->SetTitle("Counts");

    TCanvas *c = new TCanvas();
    c->Divide(2, 2);
    c->cd(1);
    h1->Draw("COLZ");
    c->cd(2);
    h1->Draw("LEGO2Z");
    c->cd(3);
    h2->Draw("COLZ");
    c->cd(4);
    h2->Draw("LEGO2Z");
}