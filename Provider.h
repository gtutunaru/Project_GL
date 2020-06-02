/*************************************************************************
                                Provider
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( Provider_H )
#define Provider_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"
#include "Cleaner.h"
#include <list>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
// Class that represents the type of users Provider. It inherits from the 
// User class and has a new attribute "cleaners" representing the list of 
// cleaners installed by this provider
//
//------------------------------------------------------------------------

class Provider : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    list<Cleaner*> getCleaners();
    // Mode d'emploi :
    // Return the list of cleaners of this Provider
 

    void ajouterCleaner(Cleaner * c);
    // Mode d'emploi :
    // Adds a new cleaner to the list of cleaners of this Provider

    string toString() const;
    // Mode d'emploi :
    // Returns the string representation of the Provider


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Provider ( const Provider & unProvider );
    // Mode d'emploi (constructeur de copie) :
    // Copy constructor of class Provider


     Provider ( );
    // Mode d'emploi :
    // Default constructor of class Provider

    Provider (string _username, string _password );
    // Mode d'emploi :
    // Constructor of class Provider who gets the username and password
    // of the user as parameters 

    virtual ~Provider ( );
    // Mode d'emploi :
    // Destructor of class Data


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    list<Cleaner*> cleaners;

};

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // Provider_H
