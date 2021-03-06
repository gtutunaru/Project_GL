/*************************************************************************
                                    User  
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

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


string User::getPassword()
{
    return password;
}


void User::setPassword(string _password)
{
    password = _password;
}


string User::getUsername()
{
    return username;
}

void User::setUsername(string _username)
{
    username = _username;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
User::User ( const User & unUser )

{
    password = unUser.password;
    username = unUser.username;
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
} //----- Fin de User (constructeur de copie)


User::User ( string _username, string _password )

{
    username = _username;
    password = _password;
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
} //----- Fin de User


User::~User ( )

{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User


