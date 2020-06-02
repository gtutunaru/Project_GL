/*************************************************************************
                                Data  
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
// Source of toRadians and distance https://www.geeksforgeeks.org/program-distance-two-points-earth/
// Utility function for converting degrees to radians
double toRadians(const double degree)
{
    // cmath library in C++ defines the constant
    // M_PI as the value of pi accurate to 1e-30
    double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

double distance(double lat1, double long1, double lat2, double long2)
{
    // Convert the latitudes and longitudes from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);

    // Haversine Formula
    double dlong = long2 - long1;
    double dlat = lat2 - lat1;

    double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in Kilometers, R = 6371
    double R = 6371;

    // Calculate the result
    ans = ans * R;

    return ans;
}

void DatePlusDays( struct tm* date, int days )
{
    const time_t ONE_DAY = 24 * 60 * 60 ;

    // Seconds since start of epoch
    time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime( &date_seconds ) ;

    //To always have the value of the hour equal to 12 to read correctly the measures
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

    //To always have the value of the hour equal to 12 to read correctly the measures
    (*date).tm_hour=12;
}

bool operator <= (const tm & date1, const tm & date2){
    // Operator used to check if date1 is smaller or equal to date2
    // by calculating the difference in seconds between the dates
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

bool Data::filterData(int id) {
    int tau = 20;
    bool found = false;
    bool data_false = false;
    Sensor* sensor;
    for(const auto& part : particulars) {
        string username = "User"+to_string(id);
        if (username == part->getUsername()) {
            found = true;
            double radius = 10;
            sensor = part->getSensor();
            int nbSensor = nbSensorInArea(sensor->getLatitude(),sensor->getLongitude(),radius);

            //Calcul of the smallest radius with at least 5 sensors inside
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
            //We obtain a pair of iterator with all of the individual's sensor measures inside
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
                            it_start->second->setFalseData(true);
                        }
                        it_start++;
                    }
                    data_false = true;
                    cout << "User " << id << " (sensor " << sensor->getSensorId() << ") was providing false data" << endl;
                    delete[] air_quality;
                    break;
                }
                delete[] air_quality;
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
    return data_false;
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
    ifstream file;
    string s;
    file.open(filename);
    if(!file) {
        cerr<< "Problem with file " << filename << ". Unable to open." << endl;
    } else {
        while (!file.eof()) {
            std::getline(file,s);
            if (s!=""){
                // Structure of cleaners.csv is Id;latitude;longitude;description;start date; end date;
                int pos = s.find(";");
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

                cleaners.insert(std::make_pair(id, c));

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

            if (s!=""){
                // Structure of sensors.csv is Id;latitude;longitude;
                int pos = s.find(";");
                int id = stoi(s.substr(6, pos-6));
                s=s.substr(pos+1, s.length()-pos);

                pos = s.find(";");
                double lat = stod(s.substr(0, pos));

                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                double longitude = stod(s.substr(0, pos));

                Sensor * s=new Sensor(id, lat, longitude);

                sensors.insert(std::make_pair(id, s));
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

            if (s!=""){
                // Structure of users.csv is username;Id_sensor;
                int pos = s.find(";");
                string username = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);

                pos = s.find(";");
                int id = stoi(s.substr(6, pos-6));
                Sensor * sensor = sensors.find(id)->second;
                Particular * p = new Particular(username, "mdp", sensor);
                particulars.push_back(p);
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
            if (s!=""){
                // Structure of providers.csv is username;Id_Cleaner
                int pos = s.find(";");
                string username = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);

                Provider * p = new Provider(username, "mdp");

                //There should be a line by provider in the csv file
                //if a provider has more cleaners, they will be all on the same line
                // e.g. Provider10;Cleaner10;Cleaner11;Cleaner12;
                while (s!=""){
                    pos = s.find(";");
                    int id = stoi(s.substr(7, pos-7));
                    Cleaner * c = cleaners.find(id)->second;
                    p->ajouterCleaner(c);
                    s=s.substr(pos+1, s.length()-pos);
                }

                providers.push_back(p);
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
            if (s!=""){
                // Structure of attributes.csv is AttributeID;Unit;Description;
                int pos = s.find(";");
                string attributeID = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                string unit = s.substr(0, pos);
                s=s.substr(pos+1, s.length()-pos);
                pos = s.find(";");
                string description = s.substr(0, pos);

                AttributeMeasure * attM = new AttributeMeasure(attributeID, unit, description);

                attributes.push_back(attM);

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

double * Data::viewQuality(double c_lat, double c_long, double radius, tm time)
{
    list<Measure*> goodMeasures;
    int nbSensors = nbSensorInArea(c_lat,c_long,radius);
    while(nbSensors<3) { //if we want to always have at least 3 sensors in the area if given radius is too small
        radius+=1;
        nbSensors = nbSensorInArea(c_lat,c_long,radius);
    }

	// It returns a pair representing the range of elements with key equal to time
    // (gives the map of measures that have happened on day "start")
    pair<Measures::iterator,Measures::iterator> result = measures.equal_range(asctime(&time));

	 //Iterate over the range
	for (multimap<string,Measure*>::iterator it = result.first; it != result.second; it++){
        int id_sensor = it->second->getSensorId();
        Sensor * s = sensors.find(id_sensor)->second;
        double s_lat = s->getLatitude();
        double s_long = s->getLongitude();
        if (distance(c_lat, c_long, s_lat, s_long) < radius && !it->second->isFalseData()){
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
    double * res = new double[5];
    if (count_o3>0 && count_so2>0 && count_no2>0 && count_pm10>0){
        res[0]=o3_tot/count_o3;
        res[1]=so2_tot/count_so2;
        res[2]=no2_tot/count_no2;
        res[3]=pm10_tot/count_pm10;
    }else{
        // If there are no good measures the method return an array filled with -1
        res[0]=-1;
        res[1]=-1;
        res[2]=-1;
        res[3]=-1;
    }

    double atmos = 0.0;
    double indexO3 = 0.0;
    double indexNO2 = 0.0;
    double indexPM10 = 0.0;
    double indexSO2 = 0.0;

    //IndexO3
    if (res[0]>=240)
    {
        indexO3 = 10;
    } else if(res[0]>=210) {
        indexO3 = 9;
    } else if(res[0]>=180) {
        indexO3 = 8;
    } else if(res[0]>=150) {
        indexO3 = 7;
    } else if(res[0]>=130) {
        indexO3 = 6;
    } else if(res[0]>=105) {
        indexO3 = 5;
    } else if(res[0]>=80) {
        indexO3 = 4;
    } else if(res[0]>=55) {
        indexO3 = 3;
    } else if(res[0]>=30) {
        indexO3 = 2;
    } else if(res[0]>=0) {
        indexO3 = 1;
    } else {
        indexO3 = -1;
    }

    //IndexSO2
    if (res[1]>=500)
    {
        indexSO2 = 10;
    } else if(res[1]>=400) {
        indexSO2 = 9;
    } else if(res[1]>=300) {
        indexSO2 = 8;
    } else if(res[1]>=250) {
        indexSO2 = 7;
    } else if(res[1]>=200) {
        indexSO2 = 6;
    } else if(res[1]>=160) {
        indexSO2 = 5;
    } else if(res[1]>=120) {
        indexSO2 = 4;
    } else if(res[1]>=80) {
        indexSO2 = 3;
    } else if(res[1]>=40) {
        indexSO2 = 2;
    } else if(res[1]>=0) {
        indexSO2 = 1;
    } else {
        indexSO2 = -1;
    }

    //IndexNO2
    if (res[2]>=400)
    {
        indexNO2 = 10;
    } else if(res[2]>=275) {
        indexNO2 = 9;
    } else if(res[2]>=200) {
        indexNO2 = 8;
    } else if(res[2]>=165) {
        indexNO2 = 7;
    } else if(res[2]>=135) {
        indexNO2 = 6;
    } else if(res[2]>=110) {
        indexNO2 = 5;
    } else if(res[2]>=85) {
        indexNO2 = 4;
    } else if(res[2]>=55) {
        indexNO2 = 3;
    } else if(res[2]>=30) {
        indexNO2 = 2;
    } else if(res[2]>=0) {
        indexNO2 = 1;
    }

    //IndexPM10
    if (res[3]>=80)
    {
        indexPM10 = 10;
    } else if(res[3]>=65) {
        indexPM10 = 9;
    } else if(res[3]>=50) {
        indexPM10 = 8;
    } else if(res[3]>=42) {
        indexPM10 = 7;
    } else if(res[3]>=35) {
        indexPM10 = 6;
    } else if(res[3]>=28) {
        indexPM10 = 5;
    } else if(res[3]>=21) {
        indexPM10 = 4;
    } else if(res[3]>=14) {
        indexPM10 = 3;
    } else if(res[3]>=7) {
        indexPM10 = 2;
    } else if(res[3]>=0) {
        indexPM10 = 1;
    }  else {
        indexPM10 = -1;
    }

    //ATMO index
    double tmp;
    if(indexO3>=indexNO2) {
        tmp = indexO3;
    } else {
        tmp = indexNO2;
    }

    if(indexPM10>=indexSO2) {
        atmos = indexPM10;
    } else {
        atmos = indexSO2;
    }

    if(tmp>atmos) atmos = tmp;

    res[4] = atmos;

    return res;
}

double * Data::viewQuality(double c_lat, double c_long, double radius, tm start, tm end)
{
    list<Measure*> goodMeasures;
    int nbSensors = nbSensorInArea(c_lat,c_long,radius);
    while(nbSensors<3) { //if we want to always have at least 3 sensors in the area if given radius is too small
        radius+=1;
        nbSensors = nbSensorInArea(c_lat,c_long,radius);
    }

    while (start<=end){
        // It returns a pair representing the range of elements with key equal to time
        // (gives the map of measures that have happened on day "start")
        pair<Measures::iterator,Measures::iterator> result = measures.equal_range(asctime(&start));

        //Iterate over the range
        for (multimap<string,Measure*>::iterator it = result.first; it != result.second; it++){
            int id_sensor = it->second->getSensorId();
            Sensor * s = sensors.find(id_sensor)->second;
            double s_lat = s->getLatitude();
            double s_long = s->getLongitude();
            if (distance(c_lat, c_long, s_lat, s_long) < radius && !it->second->isFalseData()){
                goodMeasures.push_back(it->second);
            }
        }
        // Add a day to the current day
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

    double * res = new double[5];
    if (count_o3>0 && count_so2>0 && count_no2>0 && count_pm10>0){
        // If there are no good measures the method return an array filled with -1
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

    double atmos = 0.0;
    double indexO3 = 0.0;
    double indexNO2 = 0.0;
    double indexPM10 = 0.0;
    double indexSO2 = 0.0;

    //IndexO3
    if (res[0]>=240)
    {
        indexO3 = 10;
    } else if(res[0]>=210) {
        indexO3 = 9;
    } else if(res[0]>=180) {
        indexO3 = 8;
    } else if(res[0]>=150) {
        indexO3 = 7;
    } else if(res[0]>=130) {
        indexO3 = 6;
    } else if(res[0]>=105) {
        indexO3 = 5;
    } else if(res[0]>=80) {
        indexO3 = 4;
    } else if(res[0]>=55) {
        indexO3 = 3;
    } else if(res[0]>=30) {
        indexO3 = 2;
    } else if(res[0]>=0) {
        indexO3 = 1;
    } else {
        indexO3 = -1;
    }

    //IndexSO2
    if (res[1]>=500)
    {
        indexSO2 = 10;
    } else if(res[1]>=400) {
        indexSO2 = 9;
    } else if(res[1]>=300) {
        indexSO2 = 8;
    } else if(res[1]>=250) {
        indexSO2 = 7;
    } else if(res[1]>=200) {
        indexSO2 = 6;
    } else if(res[1]>=160) {
        indexSO2 = 5;
    } else if(res[1]>=120) {
        indexSO2 = 4;
    } else if(res[1]>=80) {
        indexSO2 = 3;
    } else if(res[1]>=40) {
        indexSO2 = 2;
    } else if(res[1]>=0) {
        indexSO2 = 1;
    } else {
        indexSO2 = -1;
    }

    //IndexNO2
    if (res[2]>=400)
    {
        indexNO2 = 10;
    } else if(res[2]>=275) {
        indexNO2 = 9;
    } else if(res[2]>=200) {
        indexNO2 = 8;
    } else if(res[2]>=165) {
        indexNO2 = 7;
    } else if(res[2]>=135) {
        indexNO2 = 6;
    } else if(res[2]>=110) {
        indexNO2 = 5;
    } else if(res[2]>=85) {
        indexNO2 = 4;
    } else if(res[2]>=55) {
        indexNO2 = 3;
    } else if(res[2]>=30) {
        indexNO2 = 2;
    } else if(res[2]>=0) {
        indexNO2 = 1;
    } else {
        indexNO2 = -1;
    }

    //IndexPM10
    if (res[3]>=80)
    {
        indexPM10 = 10;
    } else if(res[3]>=65) {
        indexPM10 = 9;
    } else if(res[3]>=50) {
        indexPM10 = 8;
    } else if(res[3]>=42) {
        indexPM10 = 7;
    } else if(res[3]>=35) {
        indexPM10 = 6;
    } else if(res[3]>=28) {
        indexPM10 = 5;
    } else if(res[3]>=21) {
        indexPM10 = 4;
    } else if(res[3]>=14) {
        indexPM10 = 3;
    } else if(res[3]>=7) {
        indexPM10 = 2;
    } else if(res[3]>=0) {
        indexPM10 = 1;
    } else {
        indexPM10 = -1;
    }

    //Atmos
    double tmp;
    if(indexO3>=indexNO2) {
        tmp = indexO3;
    } else {
        tmp = indexNO2;
    }

    if(indexPM10>=indexSO2) {
        atmos = indexPM10;
    } else {
        atmos = indexSO2;
    }

    if(tmp>atmos) atmos = tmp;

    res[4] = atmos;

    return res;
}


void Data::checkImpactRadius (  int cleanId, int nbDays )
{
    double impact[5];
    int r=0; //radius
    bool isImpact = true;
    int counter = 0;

    struct tm startDate; //start day of cleaner working
    strptime(cleaners[cleanId]->getStart().c_str(), "%Y-%m-%d %H:%M:%S", &startDate);

    struct tm endDate; //last day of cleaner working
    strptime(cleaners[cleanId]->getEnd().c_str(), "%Y-%m-%d %H:%M:%S", &endDate);
    DatePlusDays(&endDate, -1); //to have last day of cleaner working, since it stops at 00:00 the next day

    struct tm beforeDate =startDate; //first day of period before cleaner
    DatePlusDays(&beforeDate, -nbDays);

    struct tm beforeStart =startDate; //the day right before start of cleaner
    DatePlusDays(&beforeStart, -1);


    //cout<<asctime(&afterDate)<<endl;
    cout<<"Information about the cleaner"<<endl<<endl;
    cout<<cleaners[cleanId]->toString()<<endl;

    while(isImpact)
    {

        //Quality before
        double * before = viewQuality(cleaners[cleanId]->getLatitude(), cleaners[cleanId]->getLongitude(), r, beforeDate, beforeStart);

        //Quality After
        double * after = viewQuality(cleaners[cleanId]->getLatitude(), cleaners[cleanId]->getLongitude(), r, startDate, endDate);

        //Impact


        if (before[4]>0 && after[4]>0) {
            counter++;
            isImpact = (after[4]+4<before[4]);
            if (isImpact)
            {
                for (int i = 0; i<5;i++)
                {
                    impact[i]= after[i]-before[i];
                }
            }
        }

        if(!isImpact && counter>1)
        {
            cout<<"There is a significant impact on Radius : "<<r<<" km"<<endl<<endl;
            cout<<"Difference O3 : "<<impact[0]<<" µg/m3"<<endl;
            cout<<"Difference SO2 : "<<impact[1]<<" µg/m3"<<endl;
            cout<<"Difference NO2 : "<<impact[2]<<" µg/m3"<<endl;
            cout<<"Difference PM10 : "<<impact[3]<<" µg/m3"<<endl;
            cout<<"Difference ATMO : "<<impact[4]<<endl;
        }
        if (r<100) {
            r+=2;
        }
        else if (r<500) {
            r+=10;
        } else if (r<1000) {
            r+= 100;
        } else {
            r+= 1000;
        }

        if (r>5000) {
            cout<<"He cleaned everything"<<endl;
            cout<<"Impact Radius : "<<r<<" km"<<endl<<endl;
            cout<<"Difference O3 : "<<impact[0]<<endl;
            cout<<"Difference SO2 : "<<impact[1]<<endl;
            cout<<"Difference NO2 : "<<impact[2]<<endl;
            cout<<"Difference PM10 : "<<impact[3]<<endl;
            cout<<"Difference ATMO : "<<impact[4]<<endl<<endl;
            break;
        }
        delete[]before;
        delete[]after;
    }
    if (counter==1){
        cout<<"There is no impact from this cleaner"<<endl;
    }
}

void Data::checkImpactValue ( int cleanId, int nbDays, double r)
{
    double impact[5];
    bool isImpact = false;

    struct tm startDate; //start day of cleaner working
    strptime(cleaners[cleanId]->getStart().c_str(), "%Y-%m-%d %H:%M:%S", &startDate);

    struct tm endDate; //last day of cleaner working
    strptime(cleaners[cleanId]->getEnd().c_str(), "%Y-%m-%d %H:%M:%S", &endDate);
    DatePlusDays(&endDate, -1); //to have last day of cleaner working, since it stops at 00:00 the next day

    struct tm beforeDate =startDate; //first day of period before cleaner
    DatePlusDays(&beforeDate, -nbDays);

    struct tm beforeStart =startDate; //the day right before start of cleaner
    DatePlusDays(&beforeStart, -1);

    cout<<"Information about the cleaner"<<endl<<endl;
    cout<<cleaners[cleanId]->toString()<<endl;

    //Quality before
    double * before = viewQuality(cleaners[cleanId]->getLatitude(), cleaners[cleanId]->getLongitude(), r, beforeDate, beforeStart);

    //Quality After
    double * after = viewQuality(cleaners[cleanId]->getLatitude(), cleaners[cleanId]->getLongitude(), r, startDate, endDate);

    //Impact
    if (before[4]>0 && after[4]>0) {
        isImpact = (after[4]+4<before[4]);
        if (isImpact)
        {
            for (int i = 0; i<5;i++)
            {
                impact[i]= after[i]-before[i];
            }
        }
    } else {
        cout<<"No sensors in this area, please try with a bigger radius"<<endl;
        return;
    }

    if(isImpact)
    {
        cout<<"There is a significant impact on Radius : "<<r<<" km"<<endl<<endl;
        cout<<"Difference O3 : "<<impact[0]<<" µg/m3"<<endl;
        cout<<"Difference SO2 : "<<impact[1]<<" µg/m3"<<endl;
        cout<<"Difference NO2 : "<<impact[2]<<" µg/m3"<<endl;
        cout<<"Difference PM10 : "<<impact[3]<<" µg/m3"<<endl;
        cout<<"Difference ATMO : "<<impact[4]<<endl;
    }

    delete[]before;
    delete[]after;

    if (!isImpact){
        cout<<"There is no impact from this cleaner in this area, but maybe on a smaller area it does."<<endl;
        cout<<"Reminder : Within the app you can check the maximum radius of impact of this cleaner"<<endl;
    }
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
    Measures::iterator it_start = measures.begin();
    Measures::iterator it_end = measures.end();
    while(it_start != it_end)
    {
        delete(it_start->second);
        it_start++;
    }

    Cleaners::iterator it_start_cleaners = cleaners.begin();
    Cleaners::iterator it_end_cleaners = cleaners.end();
    while(it_start_cleaners != it_end_cleaners)
    {
        delete(it_start_cleaners->second);
        it_start_cleaners++;
    }

    for(auto &it:attributes) delete it;
    attributes.clear();

    Sensors::iterator it_start_sensors = sensors.begin();
    Sensors::iterator it_end_sensors = sensors.end();
    while(it_start_sensors != it_end_sensors)
    {
        delete(it_start_sensors->second);
        it_start_sensors++;
    }

    for(auto &it:providers) delete it;
    providers.clear();

    for(auto &it:particulars) delete it;
    particulars.clear();

} //----- Fin de ~Data
