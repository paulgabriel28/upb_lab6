#include <iostream>
#include "DatePersonale.h"
#include "Student.h"
using namespace std;



int main()
{
    // DatePersonale a("Popescu", "Ion", 19, "Bucuresti");
    // cout << a << endl;

    // DatePersonale b;
    // cin>>b;
    // cout<<b;
    
    Student s;
    cin>>s;

    cout<<s;
    cout<<"\n------------\n";
    string prenume;
    cout << "Prenumele cautat: ";
    cin >> prenume;
    if(s.isPrenume(prenume)) {
        cout << prenume << " se afla in " << s;
    }
    else {
        cout << prenume << " nu se afla in " << s;
    }

    return 0;
}
