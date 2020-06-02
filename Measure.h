/*************************************************************************
                           Measure  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $eversmee$
    e-mail               : $erwan.versmee@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <Measure> (fichier Measure.h) ----------------
#if ! defined ( Measure_H )
#define Measure_H

using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <ctime> 

//------------------------------------------------------------------------
// Rôle de la classe <Measure>
//It defines an object measures with its attributes
//
//------------------------------------------------------------------------

class Measure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

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

    string toString();

//-------------------------------------------- Constructeurs - destructeur
    Measure ( const Measure & unMeasure );

    Measure ( );
    
    Measure (string timestamp, int sensorId, string attributeId, double value, bool falseData );

    virtual ~Measure ( );


//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
    int sensorId;
    tm timestamp;
    string attributeId;
    double value;
    bool falseData;
};

#endif // MEASURE_H


