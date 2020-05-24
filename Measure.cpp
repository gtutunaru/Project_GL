/*************************************************************************
                           User  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Measure> (fichier Measure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Measure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- 

//------Measure::----------------------------------------------- Méthodes publiques
// type Measure::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
int Measure::getSensorId()
{
    return this->sensorId;
}

void Measure::setSensorId(int sensorId)
{
    this->sensorId = sensorId;
}

tm Measure::getTimestamp()
{
    return this->timestamp;
}

void Measure::setTimestamp(tm timestamp)
{
    this->timestamp = timestamp;
}


string Measure:: getAttributeId()
{
    return this->attributeId;
}


void Measure::setAttributeId(string attributeId)
{
        this->attributeId = attributeId;
}

double Measure::getValue()
{
        return this->value;
}


void Measure::setValue(double value)
{
        this->value = value;
}

bool Measure::isFalseData()
{
        return this->falseData;
}


void Measure::setFalseData(bool falseData)
{
        this->falseData = falseData;
}


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Measure::Measure ( const Measure & unMeasure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measure>" << endl;
#endif
    timestamp = unMeasure.timestamp;
    value = unMeasure.value;
    falseData = unMeasure.falseData;
} //----- Fin de Measure (constructeur de copie)


Measure::Measure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measure>" << endl;
#endif
} //----- Fin de Measure

Measure::Measure (string _timestamp, int _sensorId, string _attributeId, double _value, bool _falseData)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measure>" << endl;
#endif
    string s_annee= _timestamp.substr(0,4);
    string s_mois = _timestamp.substr(5,7);
    string s_jour = _timestamp.substr(8,10);
    string s_heure = _timestamp.substr(11,13);
    string s_min = _timestamp.substr(14,16);
    string s_sec = _timestamp.substr(17,19);

    timestamp.tm_year=stoi(s_annee);
    timestamp.tm_mon=stoi(s_mois);
    timestamp.tm_mday=stoi(s_jour);
    timestamp.tm_hour=stoi(s_heure);
    timestamp.tm_min=stoi(s_min);
    timestamp.tm_sec=stoi(s_sec);

    sensorId = _sensorId;
    attributeId = _attributeId;
    value = _value;
    falseData = _falseData;
} //----- Fin de Measure


Measure::~Measure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Measure>" << endl;
#endif
} //----- Fin de ~Measure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


