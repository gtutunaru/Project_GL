#include <iostream>
#include "Data.h"
#include <ctime>        // struct std::tm
#include <string>
#include "Measure.h"
#include "Provider.h"
#include "AttributeMeasure.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "Particular.h"
#include "Data.h"
#include "GovAgency.h"

using namespace std;


//compares 2 dates: return the difference in seconds
//return a negative value if date1 is smaller (before date2)
/*double compareDates(struct tm *date1, struct tm * date2){
    time_t date_seconds1 = mktime( date1 );
    time_t date_seconds2 = mktime( date2 );
    double diff = difftime(date_seconds1, date_seconds2);
    return diff;
}*/

/*void DatePlusDays( struct tm* date, int days )
{
    const time_t ONE_DAY = 24 * 60 * 60 ;

    // Seconds since start of epoch
    time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime( &date_seconds ) ;
}*/

int main(){
    //cout<<"hi"<<endl;
    //cout<<"hello"<<endl;
    //Camilo was here
    //Erwan
    Data d = Data();
    d.readCleaners("dataset/cleaners.csv");
    d.readProviders("dataset/providers.csv");
    d.readSensors("dataset/sensors.csv");
    d.readAttributes("dataset/attributes.csv");
    //cout<<d.AttributesToString()<<endl;
    d.readParticulars("dataset/users.csv");
    d.readMeasures("./dataset/measurements.csv");

    /*struct tm tm;
    string s = "2019-01-01 12:00:00";
    strptime(s.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
    //cout << asctime( &tm ) << endl;

    cout<<"Air quality on  "<<asctime(&tm)<<"In area with coordinates:"<<endl;
    cout<<"Latitude = "<< "lat" <<", longitude = "<<"long"<<", radius = "<<"r"<<endl;
    double* res = d.viewQuality(44,-1,1,tm); //radius 1 and coordinates od Sensor0
    if (res[0] >= 0){
        cout<<"O3 = "<<res[0]<<endl;
        cout<<"SO2 = "<<res[1]<<endl;
        cout<<"NO2= "<<res[2]<<endl;
        cout<<"PM10 = "<<res[3]<<endl;
    } else {
        cout<<"No sensors in this area"<<endl;
    }

    cout<<endl;

    struct tm tm2;
    s = "2019-02-01 12:00:00";
    strptime(s.c_str(), "%Y-%m-%d %H:%M:%S", &tm2);
    //cout << asctime( &tm2 ) << endl;

    res = d.viewQuality(44.1,-1,100,tm, tm); //average of a month on Sensor0
    cout<<"Air quality on period\nStart: "<<asctime(&tm)<< "End: " <<asctime(&tm2)<<"In area with coordinates:"<<endl;
    cout<<"Latitude = "<< "lat" <<", longitude = "<<"long"<<", radius = "<<"r"<<endl;
    if (res[0] >= 0){
        cout<<"O3 = "<<res[0]<<endl;
        cout<<"SO2 = "<<res[1]<<endl;
        cout<<"NO2= "<<res[2]<<endl;
        cout<<"PM10 = "<<res[3]<<endl;
    } else {
        cout<<"No sensors in this area"<<endl;
    }*/

    /*struct tm* DatePlusDays( struct tm* date, int days )
    {
    struct tm* dateBis;
    // Seconds since start of epoch
    time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *dateBis = *localtime( &date_seconds ) ;
    return dateBis;
    }*/

    /*double r = 100;
    d.checkImpactValue(0,30,r);*/

    //struct tm tm2;
    //string s2 = "2019-11-20 12:00:00";
    //parses s2 into tm2 struct
    //strptime(s2.c_str(), "%Y-%m-%d %H:%M:%S", &tm2);
    //transforms tm2 into string
    //cout << asctime( &tm2 ) << endl;

    //cout<<compareDates(&tm, &tm2)<<endl;



   /* string date = "2019-11-21 12:00:00";
    string s_annee= date.substr(0,4);
    string s_mois = date.substr(5,7);
    string s_jour = date.substr(8,10);
    string s_heure = date.substr(11,13);
    string s_min = date.substr(14,16);
    string s_sec = date.substr(17,19);
    struct tm timestamp;

    timestamp.tm_year=stoi(s_annee)-1900;
    timestamp.tm_mon=stoi(s_mois)-1;
    timestamp.tm_mday=stoi(s_jour);
    timestamp.tm_hour=stoi(s_heure);
    timestamp.tm_min=stoi(s_min);
    timestamp.tm_sec=stoi(s_sec);

    cout << timestamp.tm_year << endl;
    cout << timestamp.tm_mon << endl;
    cout << timestamp.tm_mday << endl;
    cout << timestamp.tm_hour << endl;
    cout << timestamp.tm_min << endl;
    cout << timestamp.tm_sec << endl;*/

    //Data data = Data();
    /*data.readAttributes("./dataset/attributes.csv");
    cout<<data.AttributesToString();*/
    //data.readSensors("./dataset/sensors.csv");
    //data.readParticulars("./dataset/users.csv");

    //data.readMeasures("./dataset/measurements.csv");



    /*cout << asctime( &timestamp ) << endl ;

    // Date, add 10 days
    DatePlusDays( &timestamp, 10 ) ;

    // Show time/date using default formatting
    cout << asctime( &timestamp ) << endl ;*/

    /*struct tm date = { 0, 0, 12 } ;  // nominal time midday (arbitrary).
    int year = 2010 ;
    int month = 2 ;  // February
    int day = 26 ;   // 26th

    // Set up the date structure
    date.tm_year = year - 1900 ;
    date.tm_mon = month - 1 ;  // note: zero indexed
    date.tm_mday = day ;       // note: not zero indexed
*/



    /*while(1)
    {
        printf("menu:\n");
        printf("\t1: View Quality\n");
        printf("\t2: Check Impact\n");
        printf("\t3: Recherche de Parcours\n");
        printf("\t0: quitter\n");
        int choix;
        scanf("%d", &choix);
        switch(choix)
        {

        }
    }*/


    return 0;
}
