//
//  Efekty.cpp
//  PS_Xcode
//
//  Created by Remigiusz Sergiusz on 31/10/2020.
//

#include "Efekty.hpp"

//*********************************************************************************************

AudioFile<double> EFEKTY::Zmiana_Amplitudy( double Amplituda)
{
 //Amplituda =0;
    cout << "Zmiana Amplitudy rozpoczeta. Zmiana wyniesie  :"<<Amplituda<<"."<<endl;
    int kanal = 0;
    int numerSampla = PlikWaw.getNumSamplesPerChannel();
    cout<<numerSampla<<endl;
    for (int i = 0; i < numerSampla; i++)
    {
        double obecnySampel = PlikWaw.samples[kanal][i];

        if (obecnySampel!=0) {
            obecnySampel= obecnySampel + Amplituda;
            PlikWaw.samples[kanal][i]=obecnySampel;
        }
        else{
            obecnySampel =0;
            PlikWaw.samples[kanal][i]=obecnySampel;
        }

    }
    
    kanal=1;
    
    for (int i = 0; i < numerSampla; i++)
    {
        double obecnySampel = PlikWaw.samples[kanal][i];
    
        if (obecnySampel!=0) {
            obecnySampel= obecnySampel + Amplituda;
            PlikWaw.samples[kanal][i]=obecnySampel;
        }
        else{
            obecnySampel =0;
            PlikWaw.samples[kanal][i]=obecnySampel;
        }
      
    }
    
    return PlikWaw;
}

//*********************************************************************************************

AudioFile<double>  EFEKTY::Inwersja()
{
    
    
    cout << "Inwersja Rozpoczeta"<<endl;
    
    int kanal = 0;
    int NumerSampla = PlikWaw.getNumSamplesPerChannel();

    for (int i = 0; i < NumerSampla/2; i++)
    {
        double ObecnySampel = PlikWaw.samples[kanal][i];
        double NowySampel = PlikWaw.samples[kanal][NumerSampla-i];
        
        PlikWaw.samples[kanal][NumerSampla-i]= ObecnySampel;
        PlikWaw.samples[kanal][i]= NowySampel;
        
    }
    
    kanal = 1;
    
    for (int i = 0; i < NumerSampla/2; i++)
    {
        double ObecnySampel = PlikWaw.samples[kanal][i];
        double NowySampel = PlikWaw.samples[kanal][NumerSampla-i];
       
        PlikWaw.samples[kanal][NumerSampla-i]= ObecnySampel;
        PlikWaw.samples[kanal][i]= NowySampel;
        
    }
    
    return PlikWaw;
}

//*********************************************************************************************


AudioFile<double>  EFEKTY:: Wyciszenie ( int WiciszOd, int WiciszDo)
{
    
    cout << "Wyciszenie Rozpoczete. Wyciczenie od: "<< WiciszOd<<" do: "<<WiciszDo<<endl;
    
    int kanal = 0;
    int NumerSampla = PlikWaw.getNumSamplesPerChannel();

    for (int i = 0; i < NumerSampla; i++)
    {
        double ObecnySampel = PlikWaw.samples[kanal][i];
  
        if( i>= WiciszOd && i<= WiciszDo)
        {
           
            ObecnySampel =0;
            PlikWaw.samples[kanal][i]= ObecnySampel;
            
        }
        else
        {
            
            PlikWaw.samples[kanal][i]= ObecnySampel;
            
        }
    
    }
    
    kanal = 1;
    
    for (int i = 0; i < NumerSampla; i++)
    {
        double ObecnySampel = PlikWaw.samples[kanal][i];
  
        if( i>= WiciszOd && i<= WiciszDo)
        {
           
            ObecnySampel =0;
            PlikWaw.samples[kanal][i]= ObecnySampel;
            
        }
        else
        {
            
            PlikWaw.samples[kanal][i]= ObecnySampel;
            
        }
    
    }

     cout<<PlikWaw.getNumSamplesPerChannel()<<endl;
    return PlikWaw;
}



//*********************************************************************************************

AudioFile<double> EFEKTY::FiltrGornoPrzepustowy ( int Czestotliwosc)
{
    
    cout << "Filtracja Rozpoczeta. Czestotliwosc graniczna :"<<Czestotliwosc<<"."<<endl;
    
    int kanal = 0;
    int NumerSampla = PlikWaw.getNumSamplesPerChannel();

    for (int i = 0; i < NumerSampla; i++)
    {
        double ObecnySampel = PlikWaw.samples[kanal][i];
  
     PlikWaw.samples[kanal][i]= ObecnySampel;
            
    }
    
    kanal = 1;
    
    for (int i = 0; i < NumerSampla; i++)
    {
        double ObecnySampel = PlikWaw.samples[kanal][i];
  
     PlikWaw.samples[kanal][i]= ObecnySampel;
            
    }
    
    return PlikWaw;
}

//*********************************************************************************************

AudioFile<double> EFEKTY::FiltrDolnoPrzepustowy (int Czestotliwosc)
{
    
    cout << "Filtracja Rozpoczeta. Czestotliwosc graniczna :"<<Czestotliwosc<<"."<<endl;
    
    return PlikWaw;
}

//*********************************************************************************************

AudioFile<double> EFEKTY::FiltrSrodkowoPrzepustowy (int CzestotliwoscGorna, int CzestotliwoscDolna)
{
    
    cout << "Filtracja Rozpoczeta. Gorna Czestotliwosc graniczna :"<<CzestotliwoscGorna<<". Dolna Czestotliwosc graniczna "<<CzestotliwoscDolna<<endl;
    
    return PlikWaw;
}

//********************************************************************************************

AudioFile<double> EFEKTY::Zciszanie ( int WartoscZciszenia)
{
    
    cout << "Rozpoczęto Zciszanie utworu"<<endl;
    cout<<"Plik zostanie zciszony"<<WartoscZciszenia<<"razy."<<endl;
    
    int kanal = 0;
    int NumerSampla = PlikWaw.getNumSamplesPerChannel();

    for (int i = 0; i < NumerSampla; i++)
    {
        double ObecnySampel = PlikWaw.samples[kanal][i];
       // cout<<PlikWaw.samples[kanal][i]<<endl;
        if(WartoscZciszenia !=0){
            
            ObecnySampel=ObecnySampel/WartoscZciszenia;
            PlikWaw.samples[kanal][i] = ObecnySampel;
           // cout<<PlikWaw.samples[kanal][i]<<endl;
        }
        else{
            
            PlikWaw.samples[kanal][i] = ObecnySampel;
        }

    }
    
    kanal = 1;
    
    for (int i = 0; i < NumerSampla; i++)
    {
        double ObecnySampel = PlikWaw.samples[kanal][i];

        if(WartoscZciszenia !=0){
            
            ObecnySampel=ObecnySampel/WartoscZciszenia;
            PlikWaw.samples[kanal][i] = ObecnySampel;
          
        }
        else{
            
            PlikWaw.samples[kanal][i] = ObecnySampel;
        }

    }
    
    return PlikWaw;
}



//*********************************************************************************************


AudioFile<double> EFEKTY::Zglosnienie ( int WartoscZglosnienia)
{
    
    cout << "Rozpoczęto Zciszanie utworu"<<endl;
    cout<<"Plik zostanie zciszony"<<WartoscZglosnienia<<"razy."<<endl;
    
    int kanal = 0;
    int NumerSampla = PlikWaw.getNumSamplesPerChannel();

    for (int i = 0; i < NumerSampla; i++)
    {
        double ObecnySampel = PlikWaw.samples[kanal][i];
      
        if(WartoscZglosnienia !=0){
            
            ObecnySampel=ObecnySampel*WartoscZglosnienia;
            PlikWaw.samples[kanal][i] = ObecnySampel;
         
        }
        else{
            
            PlikWaw.samples[kanal][i] = ObecnySampel;
        }

    }
    
    kanal = 1;
    
    for (int i = 0; i < NumerSampla; i++)
    {
        double ObecnySampel = PlikWaw.samples[kanal][i];
      
        if(WartoscZglosnienia !=0){
            
            ObecnySampel=ObecnySampel*WartoscZglosnienia;
            PlikWaw.samples[kanal][i] = ObecnySampel;
        }
        else{
            
            PlikWaw.samples[kanal][i] = ObecnySampel;
        }

    }
    
    return PlikWaw;
}



//*********************************************************************************************
AudioFile<double> EFEKTY::Wczytaj(string Sciezka)
{

    PlikWaw.load(Sciezka);
    cout<<"Uruchomiono Wczytywanie"<<endl;

 //cout<<PlikWaw.getNumSamplesPerChannel()<<endl;
    return PlikWaw;
}

//*********************************************************************************************

void EFEKTY::Zapisz(string Sciezka)
{
    cout<<"Uruchomiono Zapis"<<endl;
    PlikWaw.save(Sciezka);
    //cout<<PlikWaw.getNumSamplesPerChannel()<<endl;

}



void EFEKTY::EksportDoTxt(string Sciezka)
{

    cout<<"Uruchomiono Eksport Do .txt"<<endl;
    int kanal = 0;
    int NumerSampla = PlikWaw.getNumSamplesPerChannel();
    ofstream zapis(Sciezka);

    zapis<<"kanal_0"<<endl;
    for (int i = 0; i < NumerSampla; i++)
    {
      zapis << PlikWaw.samples[kanal][i];
      zapis<<endl;
    }

    kanal=1;
    zapis<<"kanal_1"<<endl;
    for (int i = 0; i < NumerSampla; i++)
    {
      zapis << PlikWaw.samples[kanal][i];
      zapis<<endl;
    }

        zapis.close();

}



//void Echo(double Opoznienie, double Zanik)
//{

 // cout << "Rozpoczęto tworzenie Echa"<<endl;
 // cout<<"Zostanie nałozone echo o czasie"<<Opoznienie<<"z wspolczynnikiem zapominania."<<Zanik<<endl;






//}


 //   int kanal = 0;
 //   int NumerSampla = PlikWaw.getNumSamplesPerChannel();

   // for (int i = 0; i < NumerSampla; i++)
   // {
     //   double ObecnySampel = PlikWaw.samples[kanal][i];

     //   if(WartoscZglosnienia !=0){

       //     ObecnySampel=ObecnySampel*WartoscZglosnienia;
      //      PlikWaw.samples[kanal][i] = ObecnySampel;

       // }
     //   else{

       //     PlikWaw.samples[kanal][i] = ObecnySampel;
      //  }







