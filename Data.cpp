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

bool compareDate(tm date1,tm date2) {
    bool dateEgale = false;
    if(date1.tm_hour == date2.tm_hour &&
        date1.tm_mday == date2.tm_mday &&
        date1.tm_min == date2.tm_min &&
        date1.tm_mon == date2.tm_mon &&
        date1.tm_year == date2.tm_year) {

            dateEgale = true;
    }
    return dateEgale;
}

void Data::readMeasurements ( string filename)
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

            getline(file,timestamp_buffer,SEP);
            file.ignore(256,SEP_SENS);
            getline(file,sensorId_buffer,SEP);
            getline(file,attributeId_buffer,SEP);
            getline(file,value_buffer,SEP);

            Measure* mes = new Measure(timestamp_buffer,stoi(sensorId_buffer),attributeId_buffer,stod(value_buffer),false);
            Measures::iterator it_start = measures.begin();
            Measures::iterator it_end = measures.end();
            /*while(it_start!=it_end) {
                if(it_start->second == *mes) {

                }
            }*/

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
    getline(iss, unit, ';'));
    getline(iss, description, ';'));

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
