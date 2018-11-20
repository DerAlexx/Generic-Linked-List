//============================================================================
// Name        : student.h
// Author      : Alexander M. Westphal / Paul Schröder
// Version     : Version 1.0
// Copyright   : Alexander M. Westphal / Paul Schröder
// Description : Header-File for the Sutdent Object.
//============================================================================

#include <ostream>
#include <cstring>
#ifndef STUDENT_H_
#define STUDENT_H_
using namespace std;

class Student {
public:
    /**
     * Constructor and Destructor
     */
    Student(int MatrikelNummer, char* name, char* vorname, int geb);
    Student();

    /**
     * Getter for the Student-object
     */
    const int getMatrikelNumber() const;
    char* getName();
    char* getVorname();
    int getGeburtstag();

    /**
     * Setter for Student
     */
    void setMatrikelNumber(const int number);
    void setName(char* naName);
    void setVorname(char* voName);
    void setGeburtstag(const int geb);

    /**
     * Operator for the sutdent object
     */
    bool operator == (const Student &other);
    bool operator != (Student &other);
    bool operator <= (Student &other);
    bool operator >= (Student &other);
    bool operator < (Student &other);
    bool operator > (Student &other);

    /**
     * write und read function for streams.
     */
    virtual void write(ostream& ostr);
    virtual void read(istream& istr);

    /**
     * Attributes
     */
private:
    int matrikelNummer;
    char name[10];
    char vorname[10];
    int geburtstag;
};

/**
 * Overloading of the << operator.
 * Will return a outputstream containing the student.
 * @param ostr outputstream
 * @param stud student opject
 * @return will return a output stream
 */

ostream& operator << (ostream& ostr,Student& stud) {
    stud.write(ostr);
    return ostr;
}

/**
 * Overloading of the >> operator.
 * Will return a input stream and read the student from it.
 * @param istr input stream as param
 * @param stud student-object
 * @return will return a input stream
 */
istream& operator >> (istream& istr, Student& stud) {
    stud.read(istr);
    return istr;
}
#endif /* STUDENT_H_ */