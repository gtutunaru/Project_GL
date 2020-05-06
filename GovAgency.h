/*************************************************************************
                           GovAgency  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <GovAgency> (fichier GovAgency.h) ----------------
#if ! defined ( GovAgency_H )
#define GovAgency_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GovAgency>
//
//
//------------------------------------------------------------------------

class GovAgency : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    //GovAgency & operator = ( const GovAgency & unGovAgency );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GovAgency ( const GovAgency & unGovAgency );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

     GovAgency ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    GovAgency (string _username, string  _password );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GovAgency ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GovAgency>

#endif // GovAgency_H

