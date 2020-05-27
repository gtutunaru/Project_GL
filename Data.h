/*************************************************************************
                           Data  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $eversmee$
    e-mail               : $erwan.versmee@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <Data> (fichier Data.h) ----------------
#if ! defined ( DATA_H )
#define DATA_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <fstream>
#include <sstream>
#include "Measure.h"
#include "Provider.h"
#include "AttributeMeasure.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "Particular.h"
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef list<AttributeMeasure *> Attributes;
typedef map<int, Cleaner*> Cleaners;
typedef multimap<tm,Measure*> Measures;
typedef list<Provider *> Providers;
typedef map<int, Sensor *> Sensors;
typedef list<Particular*> Particulars;
const char SEP =';';
const char SEP_SENS = 'r';
//------------------------------------------------------------------------
// Rôle de la classe <Data>
//
//
//------------------------------------------------------------------------

class Data
{
//----------------------------------------------------------------- PUBLIC
    
public:

//----------------------------------------------------- Méthodes publiques
    void readMeasures ( string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void checkImpact ( int cleanId ) const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    void readParticulars ( string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void readCleaners ( string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void readProviders ( string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void readAttributes (string filename);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string AttributesToString() const;

    void readSensors ( string filename);
    // Mode d'emploi :
    //
    // Contrat :
    //

    double * viewQuality(double c_lat, double c_long, double radius, tm time);

    double * viewQuality(double c_lat, double c_long, double radius, tm start, tm end);
    //bool operator < (tm a, tm b);

    int nbSensorInArea(double, double, double);

//-------------------------------------------- Constructeurs - destructeur
    Data ( const Data & Data );

    Data ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Data ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    Attributes attributes;
    Cleaners cleaners;
    Measures measures;
    Providers providers;
    Sensors sensors;
    Particulars particulars;

};

#endif // DATA_H
