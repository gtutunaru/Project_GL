/*************************************************************************
                           User  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( AttributeMeasure_H )
#define AttributeMeasure_H

using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
//
//
//------------------------------------------------------------------------

class AttributeMeasure
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
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    AttributeMeasure ( const AttributeMeasure & AttributeMeasure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    AttributeMeasure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    AttributeMeasure (string unAttributeID,string unUnit,string unDescription );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AttributeMeasure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string attributeID;
    string unit;
    string description;

};

//-------------------------------- Autres définitions dépendantes de <User>

#endif // AttributeMeasure_H


