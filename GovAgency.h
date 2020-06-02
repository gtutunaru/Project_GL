/*************************************************************************
                                GovAgency
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <GovAgency> (fichier GovAgency.h) ----------------
#if ! defined ( GovAgency_H )
#define GovAgency_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"
#include "Particular.h"
#include "Sensor.h"
#include <map>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <sstream>

// typedef struct tm tm;

// typedef struct SAMPLE
// {
//     string attributeId;
//     double value;
// } result;
// typedef multimap<string, result*> valueSensor;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GovAgency>
// Class that represents the type of users of the government agency. It 
// inherits from the User class.
//
//------------------------------------------------------------------------

class GovAgency : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // bool similarSensor(Sensor* s1, Sensor* s2);
    // Mode d'emploi :
    //


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    GovAgency ( const GovAgency & unGovAgency );
    // Mode d'emploi (constructeur de copie) :
    // Copy constructor of class GovAgency

     GovAgency ( );
    // Mode d'emploi :
    // Default constructor of class GovAgency

    GovAgency (string _username, string  _password );
    // Mode d'emploi :
    // Constructor of class GovAgency who gets the username and password
    // of the user as parameters 

    virtual ~GovAgency ( );
    // Mode d'emploi :
    // Destructor of class GovAgency

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GovAgency>

#endif // GovAgency_H

