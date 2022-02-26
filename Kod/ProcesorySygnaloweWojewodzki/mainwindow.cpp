#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_WCZYTAJ_clicked()
{
         string Sciezka;
         QString SciezkaTMP;
         SciezkaTMP = ui->lineEdit_WCZYTAJ->text();
         Sciezka =  SciezkaTMP.toStdString();

       //  Sciezka = "/Users/remik/Projekty/ProcesorySygnaloweWojewodzki/test-audio.wav";
         efekty.Wczytaj(Sciezka);
         ui->label_STATUS->setText("Wczytano Plik");
         ui->label_SCIEZKA->setText(QString::fromStdString (Sciezka ));
         cout<<efekty.PlikWaw.getNumSamplesPerChannel()<<endl;
         cout<<efekty.PlikWaw.samples[0][1000]<<endl;
}

void MainWindow::on_pushButton_ZAPISZ_clicked()
{
         string Sciezka;

         QString SciezkaTMP;
         SciezkaTMP = ui->lineEdit_ZAPISZ->text();
         Sciezka =  SciezkaTMP.toStdString();

      //   Sciezka = "/Users/remik/Projekty/ProcesorySygnaloweWojewodzki/Testy/WynikZmianaAMP.wav";

         efekty.Zapisz(Sciezka);
         ui->label_STATUS->setText("Zapisano Plik");
         ui->label_SCIEZKA->setText(QString::fromStdString (Sciezka ));
         cout<<efekty.PlikWaw.getNumSamplesPerChannel()<<endl;
         cout<<efekty.PlikWaw.samples[0][1000]<<endl;
}


void MainWindow::on_pushButton_AMPLITUDA_clicked()
{
         double Amplituda;
         QString AmplitudaTMP;

         AmplitudaTMP = ui->lineEdit_AMPLITUDA->text();
         Amplituda = AmplitudaTMP.toDouble();


         efekty.Zmiana_Amplitudy( Amplituda);
         ui->label_STATUS->setText("Zmiana Amplitudy");
         cout<<efekty.PlikWaw.samples[0][1000]<<endl;
}

void MainWindow::on_pushButton_INWERSJA_clicked()
{
         efekty.Inwersja();
         ui->label_STATUS->setText("Wykonano Inwersje");
         cout<<efekty.PlikWaw.samples[0][1000]<<endl;
}

void MainWindow::on_pushButton_WYCISZ_clicked()
{
        int WyciszOd;
        int WyciszDo;

        QString WyciszOdTMP;
        QString WyciszDoTMP;

        WyciszOdTMP = ui->lineEdit_WYCISZ_OD->text();
        WyciszOd = WyciszOdTMP.toDouble();

        WyciszDoTMP = ui->lineEdit_WYCISZ_DO->text();
        WyciszDo = WyciszDoTMP.toDouble();

      //  WyciszOd =0;
      //  WyciszDo = 10000;
        efekty.Wyciszenie(WyciszOd, WyciszDo);
        ui->label_STATUS->setText("Wyciszono");
        cout<<efekty.PlikWaw.samples[0][1000]<<endl;
}

void MainWindow::on_pushButton_ZWIEKSZ_GLOSNOSC_clicked()
{
    double ZwiekszGlosnosc;
    QString ZwiekszGlosnoscTMP;

    ZwiekszGlosnoscTMP = ui->lineEdit_ZWIEKSZ_GLOSNOSC->text();
    ZwiekszGlosnosc = ZwiekszGlosnoscTMP.toDouble();
    efekty.Zglosnienie(ZwiekszGlosnosc);
    ui->label_STATUS->setText("Zwiększono Głośność");
    cout<<efekty.PlikWaw.samples[0][1000]<<endl;

}

void MainWindow::on_pushButton_ZMNIEJSZ_GLOSNOSC_clicked()
{
    double ZmniejszGlosnosc;
    QString ZmniejszGlosnoscTMP;

    ZmniejszGlosnoscTMP = ui->lineEdit_ZMNIEJSZ_GLOSNOSC->text();
    ZmniejszGlosnosc = ZmniejszGlosnoscTMP.toDouble();
    efekty.Zciszanie(ZmniejszGlosnosc);
    ui->label_STATUS->setText("Zmniejszono Głośność");
    cout<<efekty.PlikWaw.samples[0][1000]<<endl;
}

void MainWindow::on_pushButton_Export_Do_Txt_clicked()
{

    string Sciezka;

    QString SciezkaTMP;
    SciezkaTMP = ui->lineEdit_Eksport_Do_Txt->text();
    Sciezka =  SciezkaTMP.toStdString();

   // Sciezka = "/Users/remik/Projekty/ProcesorySygnaloweWojewodzki/Testy/Eksport.txt";

    efekty.EksportDoTxt(Sciezka);
    ui->label_STATUS->setText("Zapisano do pliku .txt");
    ui->label_SCIEZKA->setText(QString::fromStdString (Sciezka ));
    cout<<efekty.PlikWaw.getNumSamplesPerChannel()<<endl;
    cout<<efekty.PlikWaw.samples[0][1000]<<endl;

}




void MainWindow::on_pushButton_ECHO_clicked()
{

    int sampleRate = efekty.PlikWaw.getSampleRate();
    QString SR= QString::number(sampleRate);
    //int bitDepth = efekty.PlikWaw.getBitDepth();


   // int numSamples = efekty.PlikWaw.getNumSamplesPerChannel();

   // double lengthInSeconds = efekty.PlikWaw.getLengthInSeconds();


    //int numChannels = efekty.PlikWaw.getNumChannels();

    // bool isMono = efekty.PlikWaw.isMono();
    // bool isStereo = efekty.PlikWaw.isStereo();

    ui->label_STATUS->setText(SR);

    efekty.PlikWaw.printSummary();

 }

