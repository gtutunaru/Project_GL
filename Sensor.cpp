/*************************************************************************
                                  Sensor 
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Sensor::toString(){
  string res = "Sensor" + to_string(sensorId) + "\nLat: " + to_string(latitude) + "\nLongitude: " + to_string(longitude) +"\n" ;
  return res;
}

//Getters and Setters

int Sensor::getSensorId()
{
  return sensorId;
}

double Sensor::getLatitude()
{
  return latitude;
}

double Sensor::getLongitude()
{
  return longitude;
}

void Sensor::setLatitude(double _latitude)
{
  latitude = _latitude;
}

void Sensor::setLongitude(double _longitude)
{
  longitude = _longitude;
}

//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( const Sensor & unSensor )
{
  sensorId = unSensor.sensorId;
  latitude = unSensor.latitude;
  longitude = unSensor.longitude;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif
} //----- Fin de Sensor (constructeur de copie)

Sensor::Sensor ()
{
#ifdef MAP
    cout << "Appel au constructeur par défaut de <Sensor>" << endl;
#endif
} //----- Fin de Sensor

Sensor::Sensor (int _id, double _latitude, double _longitude)
{
    sensorId = _id;
    latitude = _latitude;
    longitude = _longitude;
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
} //----- Fin de Sensor

Sensor::~Sensor ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} //----- Fin de ~Sensor