/*************************************************************************
                           User  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type User::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
/*User & User::operator = ( const User & unUser )
// Algorithme :
//
{
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
User::User ( const User & unUser )
// Algorithme :
//
{
    password = unUser.password;
    username = unUser.username;
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
} //----- Fin de User (constructeur de copie)


User::User ( string _username, string _password )
// Algorithme :
//
{
    username = _username;
    password = _password;
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
} //----- Fin de User


User::~User ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

