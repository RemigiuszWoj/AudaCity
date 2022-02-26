//
//  Efekty.hpp
//  PS_Xcode
//
//  Created by Remigiusz Sergiusz on 31/10/2020.
//

#ifndef Efekty_hpp
#define Efekty_hpp

#include <stdio.h>
#include "Lib.h"



class EFEKTY
{
public:

AudioFile<double> PlikWaw;
    
AudioFile<double> Zmiana_Amplitudy(double Amplituda);

AudioFile<double>  Inwersja();

AudioFile<double>  Wyciszenie(int WiciszOd, int WiciszDo);

AudioFile<double> FiltrGornoPrzepustowy (int Czestotliwosc);

AudioFile<double> FiltrDolnoPrzepustowy (int Czestotliwosc);

AudioFile<double> FiltrSrodkowoPrzepustowy (int CzestotliwoscGorna, int CzestotliwoscDolna);
    
AudioFile<double> Zciszanie (int WartoscZciszenia);

AudioFile<double> Zglosnienie (int WartoscZglosnienia);

AudioFile<double> Wczytaj(string Sciezka);

void Zapisz(string Sciezka);

void EksportDoTxt (string Sciezka);

//void Echo(double Opoznienie, double Zanik);

};

#endif /* Efekty_hpp */
