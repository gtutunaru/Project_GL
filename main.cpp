#include <iostream>
#include <string.h>
using namespace std;

int main(){
    //cout<<"hi"<<endl;
    //cout<<"hello"<<endl;
    //Camilo was here
    //Erwan

    string date = "2019-11-21 12:00:00";
    string s_annee= date.substr(0,4);
    string s_mois = date.substr(5,7);
    string s_jour = date.substr(8,10);
    string s_heure = date.substr(11,13);
    string s_min = date.substr(14,16);
    string s_sec = date.substr(17,19);
    tm timestamp;

    timestamp.tm_year=stoi(s_annee);
    timestamp.tm_mon=stoi(s_mois);
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


    return 0;
}
