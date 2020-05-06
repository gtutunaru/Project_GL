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


GovAgency::GovAgency (string _mail, string _password, string _prenom, string _nom )
:User(_mail, _password,  _prenom,  _nom)
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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

