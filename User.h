/*************************************************************************
                           User  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( User_H )
#define User_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <User>
// User is the base class (mother class) of the types of users: GovAgency,
// Provider, Particular. It has 2 attributes: a username and a password.
// The password would be used for authentification eventually.
//
//------------------------------------------------------------------------

class User 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // Getters
    string getPassword();
    string getUsername();

    // Setters
    void setPassword(string _password);
    void setUsername(string _username);

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
    User ( const User & unUser );
    // Mode d'emploi (constructeur de copie) :
    // Copy constructor of class User

    User ();
    // Mode d'emploi :
    // Default constructor of class User

    User (string _username, string _password );
    // Mode d'emploi :
    // Constructor of class Provider who gets the username and password
    // of the user as parameters 

    virtual ~User ( );
    // Mode d'emploi :
    // Destructor of class User

//------------------------------------------------------------------ PRIVE

protected:
    
//----------------------------------------------------- Attributs protégés
    string password;
    string username;
};

#endif // USER_H

