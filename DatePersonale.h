#pragma once
#include <string>
#include <ostream>
using namespace std;

class DatePersonale
{
    string nume;
    string prenume;
    int varsta;
    char* oras;
    
public:
    // DatePersonale() = default;

    DatePersonale(const string &, const string &, int, const char*); // adaugat char

    friend ostream& operator<<(ostream&, const DatePersonale &);

    friend istream& operator>>(istream&,  DatePersonale &);

    //se genereaza in mod automat constructor de copiere, operator=, destructor - si functioneaza corect

    // modificari char*
    DatePersonale();
    ~DatePersonale();
    DatePersonale(const DatePersonale &);

    DatePersonale& operator=(const DatePersonale &);
    
    string getPrenume() const;
};
