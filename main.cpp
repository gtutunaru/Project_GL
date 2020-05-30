#include <iostream>
#include "Data.h"
#include <ctime>
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

int main(){

    Data d = Data();
    d.readCleaners("dataset/cleaners.csv");
    d.readProviders("dataset/providers.csv");
    d.readSensors("dataset/sensors.csv");
    d.readAttributes("dataset/attributes.csv");
    //cout<<d.AttributesToString()<<endl;
    d.readParticulars("dataset/users.csv");
    d.readMeasures("./dataset/measurements.csv");

    d.checkImpactValue(0,30,80.0);

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
