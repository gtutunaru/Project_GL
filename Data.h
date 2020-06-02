/*************************************************************************
                                    Data
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $eversmee$
    e-mail               : $erwan.versmee@insa-lyonfr$
*************************************************************************/

//---------- Interface de la classe <Data> (fichier Data.h) ----------------
#if ! defined ( DATA_H )
#define DATA_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <fstream>
#include <sstream>
#include "Measure.h"
#include "Provider.h"
#include "AttributeMeasure.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "Particular.h"
using namespace std;
//------------------------------------------------------------- Constantes
const char SEP =';';
const char SEP_SENS = 'r';
const time_t ONE_DAY = 24 * 60 * 60 ;
//------------------------------------------------------------------ Types
typedef list<AttributeMeasure *> Attributes;
typedef map<int, Cleaner*> Cleaners;
typedef multimap<string,Measure*> Measures;
typedef multimap<int,Measure*> Measures_From_Id;
typedef list<Provider *> Providers;
typedef map<int, Sensor *> Sensors;
typedef list<Particular*> Particulars;

typedef multimap<int, Measure*>::iterator measures_iterator;
//------------------------------------------------------------------------
// Rôle de la classe <Data>
// This class contains all the data in our system stored in maps and lists. 
// It also contains all the methods and functions used for the 
// functionalities of this app
//
//------------------------------------------------------------------------

class Data
{
//----------------------------------------------------------------- PUBLIC

public:

//----------------------------------------------------- Méthodes publiques
    void readMeasures ( string filename );
    // Mode d'emploi :
    // Method used to read the measures from a csv file, whose path is
    // indicated in the parameter "filename". The measures are stored in
    // two multi-maps, one with the key being the date of the measure 
    // (attribute "measures") and the second with the key being the id of 
    // the sensor doing the measure ("measures_key_id"). Since we create the 
    // measures dynamically, we store  in both multi-maps only the pointers 
    // to the Measure objects, thus having two maps instead of one is not 
    // very expensive in terms of memory
    // Contrat :
    // To work correcly, a valid path should be given

    void readParticulars ( string filename );
    // Mode d'emploi :
    // Method used to read the particular users from a csv file, whose 
    // path is indicated in the parameter "filename". The pointers to
    // the Particular objects are stored in a list which is the attribute
    // "particulars"
    // Contrat :
    // To work correcly, a valid path should be given

    void readCleaners ( string filename );
    // Mode d'emploi :
    // Method used to read the cleaners from a csv file, whose 
    // path is indicated in the parameter "filename". The pointers to
    // the Cleaner objects are stored in a map which is the attribute
    // "cleaners" and its key is the id of the Cleaner
    // Contrat :
    // To work correcly, a valid path should be given

    void readProviders ( string filename );
    // Mode d'emploi :
    // Method used to read the providers from a csv file, whose 
    // path is indicated in the parameter "filename". The pointers to
    // the Provider objects are stored in a list which is the attribute
    // "providers". Also, each provider has a list of cleaners whose
    // pointers are stored in a list in the attribute "cleaners" of "Provider"
    // Contrat :
    // To work correcly, a valid path should be given

    void readAttributes (string filename);
    // Mode d'emploi :
    // Method used to read the possible attributes from a csv file, whose 
    // path is indicated in the parameter "filename". The pointers to
    // the AttributeMeasure objects are stored in a list which is the attribute
    // "attributes".
    // Contrat :
    // To work correcly, a valid path should be given

    string AttributesToString() const;
    // Mode d'emploi :
    // Method that could be used to view all the attributes on the console
    // Contrat :
    // The method readAttributes should be called first

    void readSensors ( string filename);
    // Mode d'emploi :
    // Method used to read the sensors from a csv file, whose 
    // path is indicated in the parameter "filename". The pointers to
    // the Sensor objects are stored in a map which is the attribute
    // "sensors" and its key is the id of the Sensor
    // Contrat :
    // To work correcly, a valid path should be given

    void checkImpactValue ( int cleanId, int nbDays, double r);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void checkImpactRadius ( int cleanId, int nbDays );
    // Mode d'emploi :
    //
    // Contrat :
    //

    double * viewQuality(double c_lat, double c_long, double radius, tm time);
    // Mode d'emploi :
    // Method used to get the average of the measures that were observed on
    // a specific day ("date"), in a circle represented by coordinates of 
    // latitude and longitude and a radius around.
    // Returns array with averages of values from the measures: 1st value of o3, 
    // 2nd of so2, 3rd of no2 and 4th of pm10, 5th value is the ATMO index
    // Contrat :
    // If in the given zone there are no sensors, the radius will be incremented
    // until there are at least 3 sensors in the circle. This does not guarantee 
    // that values will be returned, since these sensors could have not provided
    // values on this specific day

    double * viewQuality(double c_lat, double c_long, double radius, tm start, tm end);
    // Mode d'emploi :
    // Method used to get the average of the measures that were observed on
    // a timepspan represented by dates "start" and "end", in a circle represented 
    // by coordinates of latitude and longitude and a radius around.
    // Returns array with averages of values from the measures: 1st value of o3, 
    // 2nd of so2, 3rd of no2 and 4th of pm10, 5th value is the ATMO index
    // Contrat :
    // If in the given zone there are no sensors, the radius will be incremented
    // until there are at least 3 sensors in the circle. This does not guarantee 
    // that values will be returned, since these sensors could have not provided
    // values on this specific day

    int nbSensorInArea(double, double, double);
    // Mode d'emploi :
    //Method used to get the exact number of sensors in a given area. The user should
    //enter a latitude, a longitude and a radius to define the area.
    // Contrat :
    //To work correctly, valid parameters should be entered by the user.

    bool filterData(int);
    // Mode d'emploi :
    //Method used to filter data provided by an individual whose id is specified
    //in the parameters. If the id corresponds to a private individual, all of its
    //measurements will be compared day by day to measurements provided by valid sensors :
    //the algorithm will determine an area in circle whose center is the coordinates
    //of the individual's sensor and the radius the smallest so that there are at
    //least 5 sensors in the area. Then, it will call viewQuality to get the average
    //quality of the air each day ; the value of each air attribute obtained with
    //valid sensors will be compared with those obtained with the individual's sensor. In
    //case the difference of two values is greater than a certain limit, all the measures 
    //of the individual are marked as false in the data structure.
    // Contrat :
    //To work correctly, a correct id corresponding to a private individual should be entered
    //by the user

//-------------------------------------------- Constructeurs - destructeur
    Data ( const Data & Data );
    // Mode d'emploi :
    // Copy constructor of class Data


    Data ();
    // Mode d'emploi :
    // Default constructor of class Data


    virtual ~Data ( );
    // Mode d'emploi :
    // Destructor of class Data
    // Is in charge of freeing all the memory allocated dynamically
    // when reading the csv files


    //------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    Attributes attributes;
    Cleaners cleaners;
    Measures measures;
    Measures_From_Id measures_key_id;
    Providers providers;
    Sensors sensors;
    Particulars particulars;

};

#endif // DATA_H
