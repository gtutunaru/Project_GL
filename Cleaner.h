/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if ! defined ( Cleaner_H )
#define Cleaner_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//This class defines an object cleaner and his attributes
//There is no particular method, only the getters, setters and toString
//------------------------------------------------------------------------

class Cleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );

    string toString() const;
    int getCleanerId() const;
    double getLatitude() const;
    double getLongitude() const;
    string getDescription() const;
    string getStart() const;
    string getEnd() const;


//-------------------------------------------- Constructeurs - destructeur
    Cleaner ( const Cleaner & unCleaner );

    Cleaner (int _id, double _latitude, double _longitude, string _description, string _start, string _end);

    virtual ~Cleaner ( );

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
    int cleanerId;
    double latitude;
    double longitude;
    string description;
    string start;
    string end;

};

#endif // Cleaner_H
