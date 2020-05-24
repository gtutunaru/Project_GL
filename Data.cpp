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

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
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

void Data::readMeasures ( string filename)
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


void Data::readCleaners ( string filename ){
    //Cleaners
    ifstream file;
    string s;
    file.open(filename);
    if(!file) {
        cerr<< "Problem with file " << filename << ". Unable to open." << endl;
    } else {
        while (!file.eof()) {
            std::getline(file,s);
            if (s!=""){
                int pos = s.find(";");
                //cout<<s.substr(7, pos-7)<<endl;
                int id = stoi(s.substr(7, pos-7));
                s=s.substr(pos+1, s.length()-pos);

                pos = s.find(";");
                double lat = stod(s.substr(0, pos));

                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                double longitude = stod(s.substr(0, pos));

                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                string description = s.substr(0, pos);

                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                string start = s.substr(0, pos);

                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                string end = s.substr(0, pos);

                Cleaner * c = new Cleaner(id, lat, longitude, description, start, end);
                cout<<(*c).toString()<<endl;
                cleaners.insert(std::make_pair(id, c));

                cout<<cleaners.find(id)->second->toString()<<endl;

            }
        }
    }
    /*std::map<int, Cleaner*>::iterator it = cleaners.begin();
    while(it != cleaners.end())
    {
        cout<<it->first<<" "<<(it->second)->toString()<<endl;
        it++;
    }*/
}

void Data::readProviders ( string filename ){
    //Cleaners
    ifstream file;
    string s;
    file.open(filename);
    if(!file) {
        cerr<< "Problem with file " << filename << ". Unable to open." << endl;
    } else {
        while (!file.eof()) {
            std::getline(file,s);
            if (s!=""){
                int pos = s.find(";");
                //cout<<s.substr(7, pos-7)<<endl;
                string username = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);

                Provider p = Provider(username, "mdp");

                //There should be a line by provider in the csv file
                //if a provider has more cleaners, they will be all on the same line
                // e.g. Provider10;Cleaner10;Cleaner11;Cleaner12;
                while (s!=""){
                    pos = s.find(";");
                    int id = stoi(s.substr(7, pos-7));
                    cout<<id<<endl;
                    Cleaner * c = cleaners.find(id)->second;
                    cout<<(*c).toString()<<endl;
                    p.ajouterCleaner(c);
                    s=s.substr(pos+1, s.length()-pos);
                }

                providers.push_back(p);
                cout<<p.toString()<<endl;
            }
        }
    }
}

//-------------------------------------------- Constructeurs - destructeur

Data::Data ( const Data & unData )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Data>" << endl;
#endif
} //----- Fin de Data (constructeur de copie)

void Data::readAttributes ( string filename)
{
  fstream entree(filename);
  entree.open(filename,ios::in);

  string attributeID, unit, description;
  string tmp,line;

  while (entree>>tmp)
  {
    getline(entree, line);
    istringstream iss(line);
    getline(iss, attributeID, ';');
    getline(iss, unit, ';');
    getline(iss, description, ';');

    AttributeMeasure attM = AttributeMeasure(attributeID, unit, description);
    attributes.push_back(attM);
  }

}

string Data::AttributesToString() const
{
  string mes = "";
  for(const auto& attribut : attributes)
  {
    mes += attribut.toString();
    mes += "\n";
  }
  return mes;
}

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
