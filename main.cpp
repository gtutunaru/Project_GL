#include <iostream>
#include "Data.h"
#include <string.h>
#include <ctime>        // struct std::tm
//#include <sstream>
//#include <locale>
using namespace std;

//compares 2 dates: return the difference in seconds
//return a negative value if date1 is smaller (before date2)
double compareDates(struct tm *date1, struct tm * date2){
    time_t date_seconds1 = mktime( date1 );
    time_t date_seconds2 = mktime( date2 );
    double diff = difftime(date_seconds1, date_seconds2);
    return diff;
}

void DatePlusDays( struct tm* date, int days )
{
    const time_t ONE_DAY = 24 * 60 * 60 ;

    // Seconds since start of epoch
    time_t date_seconds = mktime( date ) + (days * ONE_DAY) ;

    // Update caller's date
    // Use localtime because mktime converts to UTC so may change date
    *date = *localtime( &date_seconds ) ;
}

int main(){
    //cout<<"hi"<<endl;
    //cout<<"hello"<<endl;
    //Camilo was here
    //Erwan
    Data d = Data();
    d.readCleaners("dataset/cleaners.csv");
    d.readProviders("dataset/providers.csv");

    struct tm tm;
    string s = "2019-11-21 12:00:00";
    strptime(s.c_str(), "%Y-%m-%d %H:%M:%S", &tm);
    cout << asctime( &tm ) << endl;

    struct tm tm2;
    string s2 = "2019-11-20 12:00:00";
    strptime(s2.c_str(), "%Y-%m-%d %H:%M:%S", &tm2);
    cout << asctime( &tm2 ) << endl;

    cout<<compareDates(&tm, &tm2)<<endl;



    string date = "2019-11-21 12:00:00";
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
    cout << timestamp.tm_sec << endl;

    //cout << s_annee << endl;

    cout << asctime( &timestamp ) << endl ;

    // Date, add 10 days
    DatePlusDays( &timestamp, 10 ) ; 

    // Show time/date using default formatting
    cout << asctime( &timestamp ) << endl ;

    /*struct tm date = { 0, 0, 12 } ;  // nominal time midday (arbitrary).
    int year = 2010 ;
    int month = 2 ;  // February
    int day = 26 ;   // 26th

    // Set up the date structure
    date.tm_year = year - 1900 ;
    date.tm_mon = month - 1 ;  // note: zero indexed
    date.tm_mday = day ;       // note: not zero indexed
*/

   

    

    return 0;
}
