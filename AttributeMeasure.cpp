/*************************************************************************
                           User  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AttributeMeasure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type User::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
AttributeMeasure::AttributeMeasure ( const AttributeMeasure & unAttributeMeasure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
    attributeID = unAttributeMeasure.attributeID;
    unit = unAttributeMeasure.unit;
    description = unAttributeMeasure.description;
} //----- Fin de AttributeMeasure (constructeur de copie)


AttributeMeasure::AttributeMeasure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AttributeMeasure>" << endl;
#endif
} //----- Fin de User

AttributeMeasure::AttributeMeasure (string unAttributeID,string unUnit,string unDescription  )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <AttributeMeasure>" << endl;
#endif
    attributeID = unAttributeID;
    unit = unUnit;
    description = unDescription;
} //----- Fin de User


AttributeMeasure::~AttributeMeasure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <AttributeMeasure>" << endl;
#endif
} //----- Fin de ~AttributeMeasure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


