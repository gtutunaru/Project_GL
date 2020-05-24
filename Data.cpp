/*************************************************************************
                           Data  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $eversmee$
    e-mail               : $erwan.versmee@insa-lyonfr$
*************************************************************************/

//---------- Réalisation de la classe <Data> (fichier Data.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "Data.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
Measure Data::readMeasurements ( string filename)
// Algorithme :
//
{
    ifstream file;
    file.open(filename);
    if(!file) {
        cerr<< "Problem with file " << filename << ". Unable to open." << endl;
    } else {
        while (!file.eof()) {

        }
    }
} //----- Fin de readMeasurements


//-------------------------------------------- Constructeurs - destructeur

Data::Data ( const Data & unData )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Data>" << endl;
#endif
} //----- Fin de Data (constructeur de copie)

void readAttributes ( string filename);
{
  fstream entree(filename);
  entree.open(filename,ios::in);

  string attributeID, unit, description;
  string tmp,line;

  while (entree>>tmp)
  {
    getline(entree, line);
    istringstream iss(line);
    getline(iss, attributeID, ';'));
    getline(iss, attributeID, ';'));
    getline(iss, attributeID, ';'));

    AttributeMeasure attM = AttributeMeasure(attributeID, unit, description);
  }
}

Data::Data ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Data>" << endl;
#endif
} //----- Fin de Data


Data::~Data ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Data>" << endl;
#endif
} //----- Fin de ~Data
