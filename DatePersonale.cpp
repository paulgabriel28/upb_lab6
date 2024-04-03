#include "DatePersonale.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

DatePersonale::DatePersonale(const string &o, const string &s, int n, const char* loc):nume(o), prenume(s), varsta(n) {
    if(oras != NULL) {
        delete [] oras;
    }

    oras = new char[strlen(loc) + 1];
    strcpy(oras, loc);
}

ostream& operator<<(ostream& dev, const DatePersonale &a) {
    dev<<a.nume<<" "<<a.prenume<<" "<<a.varsta<< ' ' << a.oras<<endl;
    return dev;
}

istream& operator>>(istream &dev, DatePersonale &a) {
    dev>>a.nume;
    dev>>a.prenume;
    dev>>a.varsta;

    if(a.oras != NULL) {
        delete [] a.oras;
    }
    char temp[101];
    cin>>temp;
    a.oras = new char[strlen(temp) + 1];
    strcpy(a.oras, temp);
    return dev;
}

DatePersonale::DatePersonale():nume(string()), prenume(string()), varsta(0), oras(NULL){}

DatePersonale::~DatePersonale() {
    nume = "";
    prenume = "";
    varsta = 0;
    
    if(oras != NULL) {
        delete [] oras;
    }

    oras = NULL;
}

DatePersonale& DatePersonale::operator=(const DatePersonale &d) {
    nume = d.nume;
    prenume = d.prenume;
    varsta = d.varsta;
    
    if(oras != NULL) {
        delete [] oras;
        oras = NULL;
    }

    oras = new char[strlen(d.oras) + 1];
    strcpy(oras, d.oras);
    return *this;
}

DatePersonale::DatePersonale(const DatePersonale &d) {
    *this = d;
}

string DatePersonale::getPrenume() const {
    return prenume;
}