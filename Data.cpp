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

//------------------------------------------------------ Include personnel
#include "Data.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
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

                Cleaner c = Cleaner(id, lat, longitude, description, start, end);

                cleaners.push_back(c);
            }
        }
    }
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
                    auto it1 = std::next(cleaners.begin(), id);
                    Cleaner c = *it1;
                    cout<<c.toString()<<endl;
                    p.ajouterCleaner(c);
                    s=s.substr(pos+1, s.length()-pos);
                }

                providers.push_back(p);
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
