#include <iostream>
#include "Data.h"
using namespace std;

int main(){
    cout<<"hi"<<endl;
    cout<<"hello"<<endl;
    //Camilo was here
    //Erwan
    Data d = Data();
    d.readCleaners("dataset/cleaners.csv");
    d.readProviders("dataset/providers.csv");
    return 0;
}
