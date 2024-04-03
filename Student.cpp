#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student():m(NULL), nr(0), dp(DatePersonale()) {}

Student::Student(const DatePersonale &date, int n, string *str):dp(date),nr(n), m(str) {}

Student::Student(const Student &s) {
    m = NULL;
    *this = s;
}

Student& Student::operator=(const Student &s) {
    dp = s.dp;
    nr = s.nr;
    
    if(m != NULL) {
        delete [] m;
    }

    m = new string[nr];
    for(int i = 0; i < nr; i++) {
        m[i] = s.m[i];
    }
    return *this;
}

Student::~Student() {
    if(m != NULL) 
        delete [] m;

    m = NULL;
    dp = DatePersonale();
    nr = 0;
}

ostream& operator<<(ostream &dev, const Student &s) {
    dev << "Date personale: ";
    dev << s.dp; // 'endl' din operator<< - DatePersonale
    
    dev << "Numar materii: ";
    dev << s.nr << endl;
    
    cout << "Materii: ";
    for(int i = 0; i < s.nr; i++) {
        dev << s.m[i] <<' ';
    }

    dev << endl;
    return dev;
}

istream& operator>>(istream &dev, Student &s) {
    cout<<"Date personale [ Nume | Prenume | Varsta | Oras ]:\n";
    dev >> s.dp;
    cout<<"Numar materii: ";
    dev >> s.nr;
    
    if(s.m != NULL) {
        delete [] s.m;
        s.m = NULL;
    }

    cout<<"Materiile: \n";
    s.m = new string[s.nr];
    for(int i = 0; i < s.nr; i++) {
        dev >> s.m[i];
    }
    return dev;
}

bool Student::isPrenume(const string p) const {
    string prenume = dp.getPrenume();
    int poz = -1;
    poz = prenume.find(p);
    
    return poz != -1 ? 1 : 0;
}