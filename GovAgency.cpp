/*************************************************************************
                           GovAgency  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Réalisation de la classe <GovAgency> (fichier GovAgency.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "GovAgency.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type GovAgency::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*GovAgency & GovAgency::operator = ( const GovAgency & unGovAgency )
// Algorithme :
//
{
} //----- Fin de operator =

*/
//-------------------------------------------- Constructeurs - destructeur
GovAgency::GovAgency ( const GovAgency & unGovAgency )
:User(unGovAgency)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GovAgency>" << endl;
#endif
} //----- Fin de GovAgency (constructeur de copie)


GovAgency::GovAgency (string _username, string _password )
:User( _username,  _password)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GovAgency>" << endl;
#endif
} //----- Fin de GovAgency


GovAgency::~GovAgency ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GovAgency>" << endl;
#endif
    
} //----- Fin de ~GovAgency

bool GovAgency::similarSensor(Sensor* s1, Sensor* s2)
{
    valueSensor s1_list;
    valueSensor s2_list;
    string s;
    ifstream file;
    file.open("dataset/test.csv");
    if(!file) {
        cerr<< "Problem with file " << "measurements" << ". Unable to open." << endl;
        return false;
    } else {
        while (!file.eof()) {
            std::getline(file,s);
            if (s!=""){
                
                int pos = s.find(";");
                string stime = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);
                

                pos = s.find(";");
                int id = stoi(s.substr(6, pos-6));
                s=s.substr(pos+1, s.length()-pos);
                
                if (id!=s1->getSensorId()&&id!=s2->getSensorId())
                {
                    continue;
                }

                pos = s.find(";");
                string attributeId = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);
            
                pos = s.find(";");
                double valeur = stod(s.substr(0, pos));

                result r={attributeId,valeur};
                
                if(id==s1->getSensorId())
                {
                    s1_list.insert(std::make_pair(stime,&r));
                }else
                {
                    s2_list.insert(std::make_pair(stime,&r));
                }
                
            }
        }
    }
    
    double tolerance = 1.0;
    for (std::multimap<string,result*>::iterator it=s1_list.begin(); it!=s1_list.end(); ++it)
    {
        cout<<it->second->value<<endl;
        std::multimap<string,result*>::iterator iter;
        auto pr = s2_list.equal_range(it->first);
        if(pr.first != std::end(s2_list))
        {
            for (auto iter = pr.first ; iter != pr.second; ++iter)
            {
                    cout<<iter->second->value<<endl;
                if(iter->second->attributeId==it->second->attributeId&&abs(iter->second->value-it->second->value)>tolerance)
                    {
                        return false;
                    }
            }
        }
        
    }
    
    return true;
        
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

