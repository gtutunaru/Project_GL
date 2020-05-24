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
#include <map>
#include <set>
#include <list>
#include "Measure.h"
#include "Provider.h"
#include "AttributeMeasure.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "Particular.h"
//------------------------------------------------------------- Constantes
const char SEP =';';
const char SEP_SENS ='r';

//------------------------------------------------------------------ Types
typedef list<AttributeMeasure> Attributes;
typedef list<Cleaner> Cleaners;
typedef multimap<tm,Measure> Measures;
typedef list<Provider> Providers;
typedef set<Sensor> Sensors;
typedef list<Particular> Particulars;
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
    Measure readMeasurements ( string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Particular readParticulars ( string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Cleaner readCleaners ( string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Provider readProviders ( string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    AttributeMeasure readAttributes ( string filename);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Sensor readSensors ( string filename);
    // Mode d'emploi :
    //
    // Contrat :
    //

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

