/*************************************************************************
                           Data  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $erwan.versmee@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <Data> (fichier Data.h) ----------------
#if ! defined ( DATA_H )
#define DATA_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Measure.h"
#include "Provider.h"
#include "AttributeMeasure.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Data>
//
//
//------------------------------------------------------------------------

class Data
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    Measure readMeasurement ( string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Provider readProvider ( string filename );
    // Mode d'emploi :
    //
    // Contrat :
    //

    AttributeMeasure readAttribute ( string filename);
    // Mode d'emploi :
    //
    // Contrat :
    //

    


//------------------------------------------------- Surcharge d'opérateurs
    //Data & operator = ( const Data & Data );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Data ( const Data & Data );

    Data ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Data ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

};

#endif // DATA_H

