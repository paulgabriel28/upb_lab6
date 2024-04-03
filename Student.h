#pragma once
#include "DatePersonale.h"

 class Student {
    DatePersonale dp;
    int nr; //cate materii are in semestrul 2
    string *m; //vector cu numele materiilor: Programare, Matematica, Fizica

public:
    Student();

    Student(const DatePersonale&, int, string *);

    Student(const Student&);

    Student& operator=(const Student&);

    ~Student();


    friend ostream& operator<<(ostream&, const Student &);
    
    friend istream& operator>>(istream&,  Student&);

    bool isPrenume(const string) const;
};
