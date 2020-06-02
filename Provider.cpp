/*************************************************************************
                                Provider
                             -------------------
    début                : $06/05/2020$
    copyright            : (C) $2020$ par $gtutunaru$
    e-mail               : $gheorghe.tutunaru@insa-lyonfr$
*************************************************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Provider.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

list<Cleaner*> Provider::getCleaners()
{
    return cleaners;
}

void Provider::ajouterCleaner(Cleaner * c){
    cleaners.push_back(c);
}

string Provider::toString() const{
    string res = username + ' ' + password + '\n';
    for (auto const& i : cleaners) {
        res += (*i).toString();
    }
    return res;
}


//-------------------------------------------- Constructeurs - destructeur
Provider::Provider ( const Provider & unProvider )
:User(unProvider)

{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Provider>" << endl;
#endif
} //----- Fin de Provider (constructeur de copie)


Provider::Provider (string _username, string _password )
:User(_username,  _password)
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} //----- Fin de Provider


Provider::~Provider ()

{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //----- Fin de ~Provider

