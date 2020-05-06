/*************************************************************************
                           Sensor  -  description
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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

class Sensor
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool viewQuality(double lat, double long, string date_start, string date_end="");

    bool login(string mail, string password);

    bool logout();

//------------------------------------------------- Surcharge d'opérateurs
    Sensor & operator = ( const Sensor & unSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Sensor ( const Sensor & unSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Sensor (int _id, double _latitude, double _longitude, string _description);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int sensorId;
    double latitude;
    double longitude;
    string description;

};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // Sensor_H
