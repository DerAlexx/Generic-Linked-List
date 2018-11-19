//============================================================================
// Name        : student.h
// Author      : Alexander M. Westphal / Paul Schröder
// Version     : Alpha v0.1
// Copyright   : Alexander M. Westphal / Paul Schröder
// Description : ...., Ansi-style
//============================================================================

#include <ostream>
#include <cstring>
#ifndef STUDENT_H_
#define STUDENT_H_
using namespace std;

class Student {
public:
    //Konstruktor und Dekonstruktor
    Student(int MatrikelNummer, char* name, char* vorname, int geb);
    Student();

    //Getter Methoden
    const int getMatrikelNumber() const;
    char* getName();
    char* getVorname();
    int getGeburtstag();

    //Setter Methoden
    void setMatrikelNumber(const int number);
    void setName(char* naName);
    void setVorname(char* voName);
    void setGeburtstag(const int geb);

    //Methoden
    bool operator == (const Student &other);
    bool operator != (Student &other);
    bool operator <= (Student &other);
    bool operator >= (Student &other);
    bool operator < (Student &other);
    bool operator > (Student &other);
    void start();
    virtual void write(ostream& ostr);
    virtual void read(istream& istr);

private:
    //Attribute
    int matrikelNummer;
    char name[10];
    char vorname[10];
    int geburtstag;
};

ostream& operator << (ostream& ostr,Student& stud) {
    stud.write(ostr);
    return ostr;
}

istream& operator >> (istream& istr, Student& stud) {
    stud.read(istr);
    return istr;
}
#endif /* STUDENT_H_ */