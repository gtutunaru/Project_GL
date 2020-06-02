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

//----------------------------------------------------- Méthodes publiques

int Particular::getNbPoints()
{
    return nbPoints;
}

void Particular::setNbPoints(int _nbPoints)
{
    nbPoints = _nbPoints;
}

Sensor * Particular::getSensor()
{
    return sensor;
}

void Particular::setSensor(Sensor * _sensor)
{
    sensor = _sensor;
}

string Particular::toString(){
    string res = username + "\nNb points = " + to_string(nbPoints) + "\n" + sensor->toString();
    return res;
}

//-------------------------------------------- Constructeurs - destructeur
Particular::Particular ( const Particular & unParticular )
:User(unParticular)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Particular>" << endl;
#endif
} //----- Fin de Particular (constructeur de copie)


Particular::Particular (string _username, string _password, Sensor * _sensor )
:User(_username,  _password)
{
    sensor = _sensor;
    nbPoints = 0;
#ifdef MAP
    cout << "Appel au constructeur de <Particular>" << endl;
#endif
} //----- Fin de Particular


Particular::~Particular ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Particular>" << endl;
#endif
} //----- Fin de ~Particular

