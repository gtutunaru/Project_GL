/*************************************************************************
                           Particular  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <Particular> (fichier Particular.h) ----------------
#if ! defined ( Particular_H )
#define Particular_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"
#include "Sensor.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Particular>
//
//
//------------------------------------------------------------------------

class Particular : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void setSensor(Sensor _sensor);

    Sensor getSensor();

    void setNbPoints(int _nbPoints);

    int getNbPoints();


//------------------------------------------------- Surcharge d'opérateurs
    //Particular & operator = ( const Particular & unParticular );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Particular ( const Particular & unParticular );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

     Particular ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Particular (string _username, string _password, Sensor _sensor );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Particular ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int nbPoints;
    Sensor sensor;

};

//-------------------------------- Autres définitions dépendantes de <Particular>

#endif // Particular_H

