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
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
//
//
//------------------------------------------------------------------------

class User 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //bool viewQuality(double lat, double long, string date_start, string date_end=""); dans DATA

    //bool login(string mail, string password);

    //bool logout();


    string getPassword();

    void setPassword(string _password);

    string getUsername();

    void setUsername(string _username);

//------------------------------------------------- Surcharge d'opérateurs
    //User & operator = ( const User & unUser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    User ( const User & unUser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    User ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    User (string _username, string _password );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~User ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    
//----------------------------------------------------- Attributs protégés
    string password;
    string username;


};

//-------------------------------- Autres définitions dépendantes de <User>

#endif // User_H

