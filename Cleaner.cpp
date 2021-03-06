/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Cleaner::toString() const{

    string s= "Cleaner" + to_string(cleanerId) + "\nLatitude: " +  to_string(latitude)  + "\nLongitude: " +  to_string(longitude);
    s += "\nDescription: " + description  + "\nStart day: " + start  + "\nLast day: " + end + '\n';

    return s;
}

int Cleaner::getCleanerId() const
{
    return cleanerId;
}

double Cleaner::getLatitude() const
{
    return latitude;
}

double Cleaner::getLongitude() const
{
    return longitude;
}

string Cleaner::getDescription() const
{
    return description;
}

string Cleaner::getStart() const
{
    return start;
}

string Cleaner::getEnd() const
{
    return end;
}

//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner ( const Cleaner & unCleaner )

{
    cleanerId = unCleaner.getCleanerId();
    latitude = unCleaner.getLatitude();
    longitude = unCleaner.getLongitude();
    description = unCleaner.getDescription();
    start = unCleaner.getStart();
    end = unCleaner.getEnd();
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner (constructeur de copie)


Cleaner :: Cleaner (int _id, double _latitude, double _longitude, string _description, string _start, string _end)
{
    cleanerId = _id;
    latitude = _latitude;
    longitude = _longitude;
    description = _description;
    start = _start;
    end = _end;
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner


Cleaner::~Cleaner ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
} //----- Fin de ~Cleaner

