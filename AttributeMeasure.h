/*************************************************************************
                           AttributeMeasure  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2019$ par $eversmee$
    e-mail               : $erwan.versmee@insa-lyon.fr$
*************************************************************************/

//---------- Interface de la classe <AttributeMeasure> (fichier AttributeMeasure.h) ----------------
#if ! defined ( AttributeMeasure_H )
#define AttributeMeasure_H

using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>

//------------------------------------------------------------------------
// Rôle de la classe <AttributeMeasure>
//This class defines an attribute of a measure of the air quality
//
//------------------------------------------------------------------------

class AttributeMeasure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

string toString() const;

//-------------------------------------------- Constructeurs - destructeur
    AttributeMeasure ( const AttributeMeasure & AttributeMeasure );

    AttributeMeasure ();

    AttributeMeasure (string unAttributeID,string unUnit,string unDescription );

    virtual ~AttributeMeasure ( );

//------------------------------------------------------------------ PRIVE

protected:

//----------------------------------------------------- Attributs protégés
    string attributeID;
    string unit;
    string description;

};

#endif //ATTRIBUTEMEASURE_H
