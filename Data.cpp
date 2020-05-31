/*************************************************************************
                           Data  -  description
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $eversmee$
    e-mail               : $erwan.versmee@insa-lyonfr$
*************************************************************************/

//---------- Réalisation de la classe <Data> (fichier Data.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#define _XOPEN_SOURCE

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <bits/stdc++.h>
#include <time.h>
#include <ctime>
#include <cmath>


using namespace std;
//------------------------------------------------------ Include personnel
#include "Data.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
//source: of toRadiand and distance https://www.geeksforgeeks.org/program-distance-two-points-earth/
// Utility function for
// converting degrees to radians
double toRadians(const double degree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

void DatePlusDays( struct tm* date, int days )
{
    const time_t ONE_DAY = 24 * 60 * 60 ;

    // Seconds since start of epoch
    time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime( &date_seconds ) ;
    (*date).tm_hour=12;
}

void AddDay( struct tm* date )
{
    const time_t ONE_DAY = 24 * 60 * 60 ;
    // Seconds since start of epoch
    time_t date_seconds = mktime( date ) + (ONE_DAY) ;

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime( &date_seconds ) ;
    (*date).tm_hour=12;
    return;
}

double distance(double lat1, double long1,
                     double lat2, double long2)
{
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);

    // Haversine Formula
    double dlong = long2 - long1;
    double dlat = lat2 - lat1;

    double ans = pow(sin(dlat / 2), 2) +
                          cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    double R = 6371;

    // Calculate the result
    ans = ans * R;

    return ans;
}

bool operator <= (const tm & date1, const tm & date2){
    tm d1 = date1;
    tm d2 = date2;
    time_t t1 = mktime(&d1);
    time_t t2 = mktime(&d2);
    double diffSecs = difftime(t1, t2);
    return (diffSecs<=0);
}

int Data::nbSensorInArea(double c_lat, double c_long, double radius) {
    auto it = sensors.begin();
    int nbSensors=0;
    while(it!=sensors.end()){
        double lat = (it)->second->getLatitude();
        double longt = (it)->second->getLongitude();
        double dist = distance(lat,longt,c_lat,c_long);
        if(dist<radius) nbSensors++;
        it++;
    }    
    return nbSensors;
}

void Data::filterData(int id) {
    int tau = 20;
    bool found = false;
    bool data_false = false;
    Sensor* sensor;
    for(const auto& part : particulars) {
        string username = "User"+to_string(id);
        if (username == part->getUsername()) {
            found = true;
            double radius = 10;
            sensor = new Sensor(*part->getSensor());
            int nbSensor = nbSensorInArea(sensor->getLatitude(),sensor->getLongitude(),radius);
            
            //Calcul du rayon dans lequel on trouve plus de 5 senseurs
            while(nbSensor<5) {
                radius +=10;
                nbSensor = nbSensorInArea(sensor->getLatitude(),sensor->getLongitude(),radius);
            }
            //cout << "Rayon : "<< radius << ", sensor id "<< sensor->getSensorId() << ", nbSensor " << nbSensor <<  endl;
            //cout << endl;
            double o3_part = 0;
            double no2_part = 0;
	        double so2_part = 0;
            double pm10_part = 0;
            //On obtient toutes les mesures réalisées avec le senseur du particulier
            pair<measures_iterator, measures_iterator> result = measures_key_id.equal_range(sensor->getSensorId());
            for(measures_iterator it = result.first;it != result.second;it++) {
                tm date = it->second->getTimestamp();
                //cout <<"date : "<< asctime(&date) << endl;
                int cmpt_day = 0;
                while(cmpt_day<4) {
                    //cout << "Attribut actuel : " << it->second->getAttributeId() << ", valeur : "<< it->second->getValue() << endl;
                    if (it->second->getAttributeId()=="O3"){
                        o3_part = it->second->getValue();
                    } else if (it->second->getAttributeId()=="SO2"){
                        so2_part = it->second->getValue();
                    } else if (it->second->getAttributeId()=="NO2"){
                        no2_part = it->second->getValue();
                    } else if(it->second->getAttributeId()=="PM10"){
                        pm10_part = it->second->getValue();
                    }
                    it++;
                    cmpt_day++;
                }
                it--;

                //double air_quality[4];
                double* air_quality = viewQuality(sensor->getLatitude(),sensor->getLongitude(),radius,date);
                /*cout << "03 officiel : " << air_quality[0] << endl;
                cout << "N02 officiel : " << air_quality[2] << endl;
                cout << "S02 officiel : " << air_quality[1] << endl;
                cout << "PM10 officiel : " << air_quality[3] << endl;
                cout << endl;
                cout << "03 particulier : " << o3_part << endl;
                cout << "N02 particulier : " << no2_part << endl;
                cout << "S02 particulier : " << so2_part << endl;
                cout << "PM10 particulier : " << pm10_part << endl;*/

               if(abs(air_quality[0]-o3_part  )>tau || 
                  abs(air_quality[1]-so2_part )>tau ||
                  abs(air_quality[2]-no2_part )>tau ||
                  abs(air_quality[3]-pm10_part)>tau
                )
                {
                    measures_key_id.erase(result.first,result.second);
                    //cout << "J'enlève le senseur "<< sensor->getSensorId() << endl;
                    multimap<string, Measure*>::iterator it_start = measures.begin();
                    multimap<string, Measure*>::iterator it_end = measures.end();
                    while(it_start!=it_end) {
                        if(it_start->second->getSensorId()==sensor->getSensorId()) {
                            /*measures.erase(it_start);
                            it_start--;*/
                            it_start->second->setFalseData(true);
                        }
                        it_start++;
                    }
                    data_false = true;
                    cout << "User " << id << " (sensor " << sensor->getSensorId() << ") was providing false data" << endl;
                    break;
                }
                    /*bool ok = true;
                    for(const auto& mes : measures) {
                        if(mes.second->getSensorId()==sensor->getSensorId()) {
                            cout <<"On a un problème" << endl;
                            ok = false;
                            break;
                        }
                    }
                    if(ok) {
                        cout << "Tout va bien" << endl;
                    }
                    if(measures_key_id.find(sensor->getSensorId())==measures_key_id.end()) {
                        cout << "On est ok" << endl;
                    } else {
                        cout << "Erreur" << endl;
                    }

                }
                if(date.tm_mday==31 && date.tm_mon==11) {
                    cout << "je suis arrivé à la fin" << endl;
                }*/

            }
            break;
        }
    }
    if(!found) cout << "User not found (the id entered doesn't correspond to any particulars registered)" << endl;
    else {
        if(!data_false) cout << "User's data are correct : the corresponding user (sensor " << sensor->getSensorId() << ") was providing real data."<<endl;
    }
   
    /*Measures::iterator it_start = measures.begin();
    Measures::iterator it_end = measures.end();
    int nbrEnreg=0;
    int bug = 0;
    while(it_start != it_end)
    {
        if(it_start->second->getSensorId()==36 && !it_start->second->isFalseData()) {
            //cout<<it_start->first<<" ET "<<(it_start->second)->toString()<<endl;
            //cout << " id :" << (it_start->second)->getSensorId() <<"ok"<< endl;
            bug++;
        }
        if(!it_start->second->isFalseData())
        nbrEnreg++;
        it_start++;
    }
    cout << "Il y a en tout "<< nbrEnreg << " enregistrements dans la map" << endl;
    cout << "Il y a en tout "<< bug << " bugs dans la map" << endl;*/
    return;
}

void Data::readMeasures ( string filename)
// Algorithme :
//
{
    ifstream file;
    file.open(filename);
    if(!file) {
        cerr<< "Problem with file " << filename << ". Unable to open." << endl;
    } else {
        string timestamp_buffer;
        string sensorId_buffer;
        string attributeId_buffer;
        string value_buffer;

        while (!file.eof()) {

            int pos = file.tellg();
            getline(file,timestamp_buffer);

            if(timestamp_buffer.find(':')==string::npos) {
                break;
            }
            file.seekg(pos,ios_base::beg);

            getline(file,timestamp_buffer,SEP);
            file.ignore(256,SEP_SENS);
            getline(file,sensorId_buffer,SEP);
            getline(file,attributeId_buffer,SEP);
            getline(file,value_buffer,'\n');

            Measure* mes = new Measure(timestamp_buffer,stoi(sensorId_buffer),attributeId_buffer,stod(value_buffer),false);
            tm time = mes->getTimestamp();
            string s = asctime(&time);
            measures.insert(std::make_pair(s, mes));
            measures_key_id.insert(std::make_pair(stoi(sensorId_buffer),mes));
        }
        //filterData();
    }
    /*Measures::iterator it_start = measures.begin();
    Measures::iterator it_end = measures.end();
    while(it_start != it_end)
    {
        cout<<it_start->first<<" ET "<<(it_start->second)->toString()<<endl;
        it_start++;
    }*/
} //----- Fin de readMeasurements


void Data::readCleaners ( string filename ){
    //Cleaners
    ifstream file;
    string s;
    file.open(filename);
    if(!file) {
        cerr<< "Problem with file " << filename << ". Unable to open." << endl;
    } else {
        while (!file.eof()) {
            std::getline(file,s);
            if (s!=""){
                int pos = s.find(";");
                //cout<<s.substr(7, pos-7)<<endl;
                int id = stoi(s.substr(7, pos-7));
                s=s.substr(pos+1, s.length()-pos);

                pos = s.find(";");
                double lat = stod(s.substr(0, pos));

                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                double longitude = stod(s.substr(0, pos));

                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                string description = s.substr(0, pos);

                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                string start = s.substr(0, pos);

                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                string end = s.substr(0, pos);

                Cleaner * c = new Cleaner(id, lat, longitude, description, start, end);
                //cout<<(*c).toString()<<endl;
                cleaners.insert(std::make_pair(id, c));

                //cout<<cleaners.find(id)->second->toString()<<endl;

            }
        }
    }
    /*std::map<int, Cleaner*>::iterator it = cleaners.begin();
    while(it != cleaners.end())
    {
        cout<<(it->second)->toString()<<endl;
        it++;
    }*/
}

void Data::readSensors ( string filename ){
    ifstream file;
    string s;
    file.open(filename);
    if(!file) {
        cerr<< "Problem with file " << filename << ". Unable to open." << endl;
    } else {
        while (!file.eof()) {
            std::getline(file,s);
            //cout<<"line "<<s<<endl;
            if (s!=""){
                int pos = s.find(";");
                //cout<<s.substr(7, pos-7)<<endl;
                int id = stoi(s.substr(6, pos-6));
                s=s.substr(pos+1, s.length()-pos);

                pos = s.find(";");
                double lat = stod(s.substr(0, pos));

                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                double longitude = stod(s.substr(0, pos));

                Sensor * s=new Sensor(id, lat, longitude);

                sensors.insert(std::make_pair(id, s));
                //cout<<"String of provider"<<p.toString()<<endl;
            }
        }
    }
    /*std::map<int, Sensor*>::iterator it = sensors.begin();
    while(it != sensors.end())
    {
        cout<<(it->second)->toString()<<endl;
        it++;
    }*/
}

void Data::readParticulars ( string filename ){
    ifstream file;
    string s;
    file.open(filename);
    if(!file) {
        cerr<< "Problem with file " << filename << ". Unable to open." << endl;
    } else {
        while (!file.eof()) {
            getline(file,s);
            //cout<<"line "<<s<<endl;
            if (s!=""){
                int pos = s.find(";");

                string username = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);

                pos = s.find(";");
                int id = stoi(s.substr(6, pos-6));
                //cout<<"id "<<id<<endl;
                Sensor * sensor = sensors.find(id)->second;
                //cout<<"String of cleaner found "<<(*c).toString()<<endl;
                Particular * p = new Particular(username, "mdp", sensor);
                particulars.push_back(p);
                //cout<<"String of provider"<<p.toString()<<endl;
            }
        }
    }
    /*for (const auto & i : particulars) {
        cout<< (i)->toString() <<endl;
    }*/
}

void Data::readProviders ( string filename ){
    ifstream file;
    string s;
    file.open(filename);
    if(!file) {
        cerr<< "Problem with file " << filename << ". Unable to open." << endl;
    } else {
        while (!file.eof()) {
            std::getline(file,s);
            //cout<<"line "<<s<<endl;
            if (s!=""){
                int pos = s.find(";");
                //cout<<s.substr(7, pos-7)<<endl;
                string username = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);

                Provider * p = new Provider(username, "mdp");

                //There should be a line by provider in the csv file
                //if a provider has more cleaners, they will be all on the same line
                // e.g. Provider10;Cleaner10;Cleaner11;Cleaner12;
                while (s!=""){
                    //cout<<"left of line "<<s<<endl;
                    pos = s.find(";");
                    int id = stoi(s.substr(7, pos-7));
                    //cout<<"id "<<id<<endl;
                    Cleaner * c = cleaners.find(id)->second;
                    //cout<<"String of cleaner found "<<(*c).toString()<<endl;
                    p->ajouterCleaner(c);
                    s=s.substr(pos+1, s.length()-pos);
                }

                providers.push_back(p);
                //cout<<"String of provider"<<p.toString()<<endl;
            }
        }
    }
    /*for (const auto & i : providers) {
        cout<< (i)->toString() <<endl;
    }*/
}

void Data::readAttributes ( string filename)
{
    ifstream file;
    string s;
    file.open(filename);
    if(!file) {
        cerr<< "Problem with file " << filename << ". Unable to open." << endl;
    } else {
        while (!file.eof()) {
            std::getline(file,s);
            //cout<<"line "<<s<<endl;
            if (s!=""){
                int pos = s.find(";");
                string attributeID = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                string unit = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                string description = s.substr(0, pos);

                //cout<<attributeID<<endl<<unit<<endl<<description<<endl<<endl;

                AttributeMeasure * attM = new AttributeMeasure(attributeID, unit, description);

                attributes.push_back(attM);

                //cout<<"String of provider"<<p.toString()<<endl;
            }
        }
    }
}

string Data::AttributesToString() const
{
    string mes = "";
    for(const auto& attribut : attributes)
    {
        mes += attribut->toString();
        mes += "\n";
    }
    return mes;
}
//return table with averages of values on a day from sensors in a circle
//1st value of o3, 2nd of so2, 3rd of no2 and 4th of pm10
double * Data::viewQuality(double c_lat, double c_long, double radius, tm time)
{
    list<Measure*> goodMeasures;
    

	// It returns a pair representing the range of elements with key equal to time
    pair<Measures::iterator,Measures::iterator> result = measures.equal_range(asctime(&time));
    //auto result = measures.equal_range(time);
	//cout << "All values for key "<<asctime( &time )<<" are," << endl;

	 //Iterate over the range
	for (multimap<string,Measure*>::iterator it = result.first; it != result.second; it++){
        int id_sensor = it->second->getSensorId();
        Sensor * s = sensors.find(id_sensor)->second;
        double s_lat = s->getLatitude();
        double s_long = s->getLongitude();
        if (distance(c_lat, c_long, s_lat, s_long) < radius){
            goodMeasures.push_back(it->second);
        }
    }
    double o3_tot = 0;
    double no2_tot = 0;
	double so2_tot = 0;
    double pm10_tot = 0;
    double count_o3 = 0;
    double count_no2 = 0;
    double count_so2 = 0;
    double count_pm10 = 0;

    for (const auto & i : goodMeasures) {
        if (i->getAttributeId()=="O3"){
            count_o3++;
            o3_tot += i->getValue();
        } else if (i->getAttributeId()=="SO2"){
            count_so2++;
            so2_tot += i->getValue();
        } else if (i->getAttributeId()=="NO2"){
            count_no2++;
            no2_tot += i->getValue();
        } else if(i->getAttributeId()=="PM10"){
            count_pm10++;
            pm10_tot += i->getValue();
        }
    }
    double * res = new double[4];
    if (count_o3>0){
        res[0]=o3_tot/count_o3;
        res[1]=so2_tot/count_so2;
        res[2]=no2_tot/count_no2;
        res[3]=pm10_tot/count_pm10;
    }else{
        res[0]=-1;
        res[1]=-1;
        res[2]=-1;
        res[3]=-1;
    }
    
    return res;
}

double * Data::viewQuality(double c_lat, double c_long, double radius, tm start, tm end)
{
    list<Measure*> goodMeasures;

    while (start<=end){

        // It returns a pair representing the range of elements with key equal to time
        pair<Measures::iterator,Measures::iterator> result = measures.equal_range(asctime(&start));
        //cout << "All values for key "<<asctime( &start )<<" are," << endl;

        //Iterate over the range
        for (multimap<string,Measure*>::iterator it = result.first; it != result.second; it++){
            int id_sensor = it->second->getSensorId();
            Sensor * s = sensors.find(id_sensor)->second;
            double s_lat = s->getLatitude();
            double s_long = s->getLongitude();
            if (distance(c_lat, c_long, s_lat, s_long) < radius){
                //cout<<it->second->toString()<<endl;
                goodMeasures.push_back(it->second);
            }
        }
        AddDay(&start);
    }


    double o3_tot = 0;
    double no2_tot = 0;
	double so2_tot = 0;
    double pm10_tot = 0;
    double count_o3 = 0;
    double count_no2 = 0;
    double count_so2 = 0;
    double count_pm10 = 0;

    for (const auto & i : goodMeasures) {
        //cout<<i->toString()<<endl;
        if (i->getAttributeId()=="O3"){
            count_o3++;
            o3_tot += i->getValue();
        } else if (i->getAttributeId()=="SO2"){
            count_so2++;
            so2_tot += i->getValue();
        } else if (i->getAttributeId()=="NO2"){
            count_no2++;
            no2_tot += i->getValue();
        } else if(i->getAttributeId()=="PM10"){
            count_pm10++;
            pm10_tot += i->getValue();
        }
    }
    //cout<<o3_tot<<endl;
    //static double res[4];
    double * res = new double[4];
    if (count_o3>0){
        res[0]=o3_tot/count_o3;
        res[1]=so2_tot/count_so2;
        res[2]=no2_tot/count_no2;
        res[3]=pm10_tot/count_pm10;
    }else{
        res[0]=-1;
        res[1]=-1;
        res[2]=-1;
        res[3]=-1;
    }
    
    return res;
}
//Faire Getters de Cleaner!!!
/*
void Data::checkImpactRadius (  int cleanId, int nbDays  )
{
    double impact[4];
    int r=10; //radius
    bool isImpact = false;

    tm startDate;
    //parses s2 into tm2 struct
    strptime(cleaners[cleanId]->getStart().c_str(), "%Y-%m-%d %H:%M:%S", &startDate);

    while(!isImpact)
    {
        //Quality Before
        double * before = this->viewQuality(cleaners[cleanId]->getLatitude(), cleaners[cleanId]->getLongitude(), r, *DatePlusDays( &startDate, -30), startDate);
        //Quality After
        double * after = this->viewQuality(cleaners[cleanId]->getLatitude(), cleaners[cleanId]->getLongitude(), r, startDate, *DatePlusDays( &startDate, nbDays));
        //Impact
        for (int i = 0; i<4;i++)
        {
            impact[i]= after[i]-before[i];
            if (abs(impact[i])>before[i]/10.0)
            {
                isImpact = true;
            }
            //SO2,NO2, PM10
        }
        if(isImpact)
        {
            cout<<"Impact Radius : "<<r<<" km"<<endl<<endl;
            cout<<"Difference O3 : "<<impact[0]<<endl;
            cout<<"Difference SO2 : "<<impact[1]<<endl;
            cout<<"Difference NO2 : "<<impact[2]<<endl;
            cout<<"Difference PM10 : "<<impact[3]<<endl;
        }
        r+=10;
    }
}*/

void Data::checkImpactValue ( int cleanId, int nbDays, double r)
{
    double impact[4];
    cout<<"So far so good 3"<<endl;
    struct tm startDate; //start day of cleaner working
    strptime(cleaners[cleanId]->getStart().c_str(), "%Y-%m-%d %H:%M:%S", &startDate);
    struct tm endDate; //last day of cleaner working
    strptime(cleaners[cleanId]->getEnd().c_str(), "%Y-%m-%d %H:%M:%S", &endDate);

    struct tm beforeDate =startDate; //pour ajouter des jours, faut utiliser comme ca
    DatePlusDays(&beforeDate, -nbDays);

    cout<<asctime(&beforeDate)<<endl;
    cout<<asctime(&startDate)<<endl;

    struct tm afterDate =endDate;
    DatePlusDays(&afterDate, nbDays);
    cout<<asctime(&afterDate)<<endl;

    //Quality before
    double * before = viewQuality(cleaners[cleanId]->getLatitude(), cleaners[cleanId]->getLongitude(), r, beforeDate, startDate);
    //Quality After
    double * after = viewQuality(cleaners[cleanId]->getLatitude(), cleaners[cleanId]->getLongitude(), r, endDate, afterDate);
    //Impact
    cout<<"Test before"<<endl;
    for (int i = 0; i<4;i++)
    {
        //cout<<before[i]<<endl;
        //cout<<after[i]<<endl;
        if (before[i]>=0 && after[i]>=0){
            impact[i]= after[i]-before[i];
            //cout<<before[i]<<" "<<after[i]<<endl;
        }
        //impact[i]= after[i]-before[i];
        //cout<<before[i]<<endl;
    }
    cout<<"On a radius of "<<r<<" km the impact is :"<<endl<<endl;
    cout<<"Difference O3 : "<<impact[0]<<endl;
    cout<<"Difference SO2 : "<<impact[1]<<endl;
    cout<<"Difference NO2 : "<<impact[2]<<endl;
    cout<<"Difference PM10 : "<<impact[3]<<endl;
    
    cout<<"finished value"<<endl;
}

//-------------------------------------------- Constructeurs - destructeur

Data::Data ( const Data & unData )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Data>" << endl;
#endif
} //----- Fin de Data (constructeur de copie)

Data::Data ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Data>" << endl;
#endif
} //----- Fin de Data


Data::~Data ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Data>" << endl;
#endif
} //----- Fin de ~Data
