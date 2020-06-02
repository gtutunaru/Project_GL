/*************************************************************************
                           Measure  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $eversmee$
    e-mail               : $erwan.versmee@insa-lyonfr$
*************************************************************************/

//---------- Réalisation de la classe <Measure> (fichier Measure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Measure.h"

//----------------------------------------------- Méthodes publiques

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

string Measure::toString() {
    char t[80];
    strftime(t,100, "%Y-%m-%d %H:%M:%S", &timestamp);
    string s = "Measure " + to_string(sensorId) + " " + t
    + " " + attributeId + " " + to_string(value) + " " + to_string(falseData) + '\n';
    return s;
}

//-------------------------------------------- Constructeurs - destructeur
Measure::Measure ( const Measure & unMeasure )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measure>" << endl;
#endif
    timestamp = unMeasure.timestamp;
    value = unMeasure.value;
    falseData = unMeasure.falseData;
} //----- Fin de Measure (constructeur de copie)


Measure::Measure ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Measure>" << endl;
#endif
} //----- Fin de Measure

Measure::Measure (string _timestamp, int _sensorId, string _attributeId, double _value, bool _falseData)
{
#ifdef MAP
    cout << "Appel au constructeur de <Measure>" << endl;
#endif

    strptime(_timestamp.c_str(), "%Y-%m-%d %H:%M:%S", &timestamp);

    sensorId = _sensorId;
    attributeId = _attributeId;
    value = _value;
    falseData = _falseData;
} //----- Fin de Measure


Measure::~Measure ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Measure>" << endl;
#endif
} //----- Fin de ~Measure

