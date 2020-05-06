/*************************************************************************
                           Particular  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Réalisation de la classe <Particular> (fichier Particular.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Particular.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Particular::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
int Particular::getNbPoints()
{
    return nbPoints;
}

void Particular::setNbPoints(int _nbPoints)
{
    nbPoints = _nbPoints;
}

double Particular::getLatitude()
{
    return latitude;
}

void Particular::setLatitude(double _latitude)
{
    latitude = _latitude;
}

double Particular::getLongitude()
{
    return longitude;
}


void Particular::setLongitude(double _longitude)
{
    longitude = _longitude;
}


//------------------------------------------------- Surcharge d'opérateurs
/*Particular & Particular::operator = ( const Particular & unParticular )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
Particular::Particular ( const Particular & unParticular )
:User(unParticular)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Particular>" << endl;
#endif
} //----- Fin de Particular (constructeur de copie)


Particular::Particular (string _username, string _password, double _latitude, double _longitude )
:User(_username,  _password)
// Algorithme :
//
{
    latitude = _latitude;
    longitude = _longitude;
    nbPoints = 0;
#ifdef MAP
    cout << "Appel au constructeur de <Particular>" << endl;
#endif
} //----- Fin de Particular


Particular::~Particular ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Particular>" << endl;
#endif
} //----- Fin de ~Particular


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

