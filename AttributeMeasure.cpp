/*************************************************************************
                           AttributeMeasure
            Class representing the possible attributes of a measure
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <AttributeMeasure> (fichier AttributeMeasure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

//------------------------------------------------------ Include personnel
#include "AttributeMeasure.h"
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string AttributeMeasure::toString() const
{
  string mes = "Attribute \n";
  mes+= ("Id : "+ attributeID+"\n");
  mes+= ("Unit : "+ unit+"\n");
  mes+= ("description : "+ description+"\n");
  return mes;
}


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
AttributeMeasure::AttributeMeasure ( const AttributeMeasure & unAttributeMeasure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <AttributeMeasure>" << endl;
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
} //----- Fin de AttributeMeasure

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
} //----- Fin de AttributeMeasure


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
