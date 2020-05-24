/*************************************************************************
                           User  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Measure> (fichier Measure.h) ----------------
#if ! defined ( Measure_H )
#define Measure_H

using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AttributeMeasure>
//
//
//------------------------------------------------------------------------

class Measure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    int getSensorId();
    tm getTimestamp();
    string getAttributeId();
    double getValue();
    bool isFalseData();

    void setSensorId(int);
    void setTimestamp(tm);
    void setAttributeId(string);
    void setValue(double);
    void setFalseData(bool);
//------------------------------------------------- Surcharge d'opérateurs
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Measure ( const Measure & unMeasure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Measure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    Measure (string timestamp, int sensorId, string attributeId, double value, bool falseData );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Measure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int sensorId;
    tm timestamp;
    string attributeId;
    double value;
    bool falseData;
};

//-------------------------------- Autres définitions dépendantes de <AttributeMeasure>

#endif // AttributeMeasure_H


