/*************************************************************************
                                    Sensor
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( Sensor_H )
#define Sensor_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
// Class that represents the object Sensor. It has an Id, a latitude and
// longitude
//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // Getters
    int getSensorId();
    double getLatitude();
    double getLongitude();

    // Setters
    void setLatitude(double _latitude);
    void setLongitude(double _longitude);

    string toString();
    // Mode d'emploi :
    // Returns the string representation of the Sensor

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Sensor ( const Sensor & unSensor );
    // Mode d'emploi:
    // Copy constructor of class Sensor

    Sensor();
    // Mode d'emploi:
    // Default constructor of class Provider

    Sensor (int _id, double _latitude, double _longitude);
    // Mode d'emploi :
    // Constructor of class Provider who gets the id, latitude and longitude
    // of the sensor as parameters 

    virtual ~Sensor ( );
    // Mode d'emploi :
    // Destructor of class Data

    
//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
    int sensorId;
    double latitude;
    double longitude;

};

#endif // Sensor_H
