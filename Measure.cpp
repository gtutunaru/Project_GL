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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Measure::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


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

Measure::Measure (string untimestamp,string unvalue,bool unfalseData)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measure>" << endl;
#endif
    timestamp = untimestamp;
    value = unvalue;
    falseData = unfalseData;
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


