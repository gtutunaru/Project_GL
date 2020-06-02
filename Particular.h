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

//------------------------------------------------------------------------
// Rôle de la classe <Particular>
//This class defines an object Particular (representing a private individual)
//with its attributes
//------------------------------------------------------------------------

class Particular : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void setSensor(Sensor * _sensor);

    Sensor * getSensor();

    void setNbPoints(int _nbPoints);

    int getNbPoints();

    string toString();

//-------------------------------------------- Constructeurs - destructeur
    Particular ( const Particular & unParticular );

     Particular ( );

    Particular (string _username, string _password, Sensor * _sensor );

    virtual ~Particular ( );

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
    int nbPoints;
    Sensor * sensor;

};


#endif // PARTICULAR_H

