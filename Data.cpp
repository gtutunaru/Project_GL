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
            string timestamp_buffer;
            string sensorId_buffer;
            string attributeId_buffer;
            string value_buffer;

            
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
