#include <iostream>
#include <ctime>
#include <string>
#include <bits/stdc++.h>
#include "Measure.h"
#include "Provider.h"
#include "AttributeMeasure.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "Particular.h"
#include "Data.h"
#include "GovAgency.h"

bool showTime = true;

using namespace std;

void viewQualityDay (Data & d){
    clock_t startClock, endClock;
    cout<<"\nInsert date in format YYYY-MM-DD : ";
    string s;
    cin>>s;
    s += " 12:00:00";
    struct tm date;
    strptime(s.c_str(), "%Y-%m-%d %H:%M:%S", &date);
    cout<<"Insert latitude: ";
    double lat;
    cin>>lat;
    cout<<"Insert longitude: ";
    double longitude;
    cin>>longitude;
    cout<<"Insert radius of area to check : ";
    double radius;
    cin>>radius;
    cout<<endl;
    startClock = clock();
    double * res = d.viewQuality(lat, longitude, radius, date);
    endClock = clock();
    if (res[0]>=0){
        cout<<"Air Quality Index: "<<res[4]<<endl;
        cout<<"O3: "<<res[0]<<endl;
        cout<<"SO2: "<<res[1]<<endl;
        cout<<"NO3: "<<res[2]<<endl;
        cout<<"PM10: "<<res[3]<<endl;
    } else{
        cout<<"No sensors in the area"<<endl;
    }
    double time_taken = double(endClock - startClock) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    delete[]res;
}

void viewQualityTimespan (Data & d){
    clock_t startClock, endClock;
    cout<<"\nInsert first date in format YYYY-MM-DD : ";
    string s;
    cin>>s;
    s += " 12:00:00";
    struct tm start;
    strptime(s.c_str(), "%Y-%m-%d %H:%M:%S", &start);
    cout<<"Insert last date in format YYYY-MM-DD : ";
    cin>>s;
    s += " 12:00:00";
    struct tm end;
    strptime(s.c_str(), "%Y-%m-%d %H:%M:%S", &end);
    cout<<"Insert latitude: ";
    double lat;
    cin>>lat;
    cout<<"Insert longitude: ";
    double longitude;
    cin>>longitude;
    cout<<"Insert radius of area to check : ";
    double radius;
    cin>>radius;
    cout<<endl;
    startClock = clock();
    double * res = d.viewQuality(lat, longitude, radius, start, end);
    endClock = clock();
    if (res[0]>=0){
        cout<<"Air Quality Index: "<<res[4]<<endl;
        cout<<"O3: "<<res[0]<<endl;
        cout<<"SO2: "<<res[1]<<endl;
        cout<<"NO3: "<<res[2]<<endl;
        cout<<"PM10: "<<res[3]<<endl;
    } else{
        cout<<"No sensors in the area"<<endl;
    }
    double time_taken = double(endClock - startClock) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    delete[]res;
}

int main(){
    cout<<"\n=============Starting application AirWatcher============="<<endl;
    cout<<"\nLoading data..."<<endl;

    Data d = Data();
    d.readCleaners("dataset/cleaners.csv");
    d.readProviders("dataset/providers.csv");
    d.readSensors("dataset/sensors.csv");
    d.readAttributes("dataset/attributes.csv");
    d.readParticulars("dataset/users.csv");
    d.readMeasures("./dataset/measurements.csv");

    //d.checkImpactValue(0,30,1000.0);

    //struct tm startDate; //start day of cleaner working
    //strptime("2019-02-01 12:00:00", "%Y-%m-%d %H:%M:%S", &startDate);
    //struct tm endDate; //last day of cleaner working
    //strptime("2019-03-01 00:00:00", "%Y-%m-%d %H:%M:%S", &endDate);
    //cout<<endl;
    //d.checkImpactRadius(0,30);
    //d.checkImpactRadius(1,30);

    //struct tm beforeDate ; //pour ajouter des jours, faut utiliser comme ca
    //strptime("2019-01-02 12:00:00", "%Y-%m-%d %H:%M:%S", &beforeDate);

    //cout<<asctime(&beforeDate)<<endl;
    //cout<<asctime(&startDate)<<endl;

    //struct tm afterDate ;
    //strptime("2019-03-31 00:00:00", "%Y-%m-%d %H:%M:%S", &afterDate);

    //double * res = d.viewQuality(46.666667, 3.666667, 80, beforeDate, startDate);
    //double * res2 = d.viewQuality(46.666667, 3.666667, 80, endDate, afterDate);
    //cout<<res[4]<<" "<<res2[4]<<endl;
    //cout<<endl;

    //d.filterData(1);

    //d.checkImpactRadius(0,30);




    bool exit = false;
    bool exitGov =false;
    bool exitProv = false;
    bool exitPart = false;
    double time_taken;
    while(!exit)
    {
        cout<<"\nMain menu:"<<endl;
        /*printf("\t1: View Quality\n");
        printf("\t2: Check Impact\n");
        printf("\t3: Recherche de Parcours\n");*/
        cout<<"\t1: Log in as a member of the government agency"<<endl;
        cout<<"\t2: Log in as a provider"<<endl;
        cout<<"\t3: Log in as a particular"<<endl;
        cout<<"\t0: Exit the application"<<endl;
        int choix;
        cin>>choix;
        switch(choix)
        {
            case 1:
                while(!exitGov){
                    cout<<"\nHello, what do you want to do?"<<endl;
                    cout<<"\t1: View quality of the air on a given date"<<endl;
                    cout<<"\t2: View quality of the air on a timespan"<<endl;
                    cout<<"\t3: Analyze data from a private individual"<<endl;
                    cout<<"\t0: Log out"<<endl;
                    int choix2;
                    cin>>choix2;
                    switch(choix2){
                        case 1:
                            viewQualityDay(d);
                            break;
                        case 2:
                            viewQualityTimespan(d);
                            break;
                        case 3:
                            cout<<"\nInsert id of private individual to analyze: ";
                            int id;
                            cin>>id;
                            cout<<endl;
                            clock_t startClock, endClock;
                            startClock = clock();
                            d.filterData(id);
                            endClock = clock();
                            time_taken = double(endClock - startClock) / double(CLOCKS_PER_SEC);
                            cout << "Time taken by program is : " << fixed
                                << time_taken << setprecision(5);
                            cout << " sec " << endl;
                            break;
                        case 0:
                            exitGov = true;
                            break;
                        default:
                            cout<<"Invalid input"<<endl;
                            break;
                    }
                }
                break;
            case 2:
                while(!exitProv){
                    cout<<"\nHello, what do you want to do?:"<<endl;
                    cout<<"\t1: View quality of the air on a given date"<<endl;
                    cout<<"\t2: View quality of the air on a timespan"<<endl;
                    cout<<"\t3: Check impact of a cleaner"<<endl;
                    cout<<"\t0: Log out"<<endl;
                    int choix3;
                    cin>>choix3;
                    switch(choix3){
                        case 1:
                            viewQualityDay(d);
                            break;
                        case 2:
                            viewQualityTimespan(d);
                            break;
                        case 3:
                            //d.checkImpact();
                            break;
                        case 0:
                            exitProv = true;
                            break;
                        default:
                            cout<<"Invalid input"<<endl;
                            break;
                    }
                }
                break;
            case 3:
                while(!exitPart){
                    cout<<"\nHello, what do you want to do?:"<<endl;
                    cout<<"\t1: View quality of the air on a given date"<<endl;
                    cout<<"\t2: View quality of the air on a timespan"<<endl;
                    cout<<"\t0: Log out"<<endl;
                    int choix4;
                    cin>>choix4;
                    switch(choix4){
                        case 1:
                            viewQualityDay(d);
                            break;
                        case 2:
                            viewQualityTimespan(d);
                            break;
                        case 0:
                            exitPart = true;
                            break;
                        default:
                            cout<<"Invalid input"<<endl;
                            break;
                    }
                }
                break;
            case 0:
                exit = true;
                break;
            default:
                cout<<"Invalid input"<<endl;
                break;
        }
    }


    return 0;
}
