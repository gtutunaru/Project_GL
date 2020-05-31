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
const char SEP =';';
const char SEP_SENS = 'r';
const time_t ONE_DAY = 24 * 60 * 60 ;
//------------------------------------------------------------------ Types
typedef list<AttributeMeasure *> Attributes;
typedef map<int, Cleaner*> Cleaners;
typedef multimap<string,Measure*> Measures;
typedef multimap<int,Measure*> Measures_From_Id;
typedef list<Provider *> Providers;
typedef map<int, Sensor *> Sensors;
typedef list<Particular*> Particulars;

typedef multimap<int, Measure*>::iterator measures_iterator;
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

    void checkImpactValue ( int cleanId, int nbDays, double r);

    void checkImpactRadius ( int cleanId, int nbDays );
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

    void filterData(int);

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
    Measures_From_Id measures_key_id;
    Providers providers;
    Sensors sensors;
    Particulars particulars;

};

#endif // DATA_H
