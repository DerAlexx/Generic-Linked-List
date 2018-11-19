//============================================================================
// Name        : student.cpp
// Author      : Alexander M. Westphal / Paul Schröder
// Version     : Alpha v0.1
// Copyright   : Alexander M. Westphal / Paul Schröder
// Description : ..., Ansi-style
//============================================================================

#include "student.h"
#include <iostream>


/**
 * Getter for the Matrikelnummer.
 * return the Matrikelnummer.
 */
const int Student::getMatrikelNumber() const {
    return matrikelNummer;
}

/**
 * Getter for the Birthday.
 * return the Birthday.
 */
int Student::getGeburtstag() {
    return geburtstag;
}

/**
 * Getter for the Name.
 * return the name.
 */
char* Student::getName() {
    return name;
}

/**
 * Getter for the vorname
 * return the vorname;
 */
char* Student::getVorname() {
    return vorname;
}

/**
 * Setter for the MatrikelNummer
 * MatrikelNummer will be set to given parameter.
 */
void Student::setMatrikelNumber(const int number) {
    matrikelNummer = number;
}

/**
 * Setter for the Name.
 * Name will be set to the given parameter.
 */
void Student::setName(char* name2) {
    strncpy(name2, this -> name, sizeof(name2));
}

/**
 * Setter for the Vorname.
 * Vorname will be set to given parameter.
 */
void Student::setVorname(char* vorname2) {
    strncpy(vorname2, this -> vorname, sizeof(vorname2));
}

/**
 * Setter for the Birthday.
 * Birthday will be set to given parameter.
 */
void Student::setGeburtstag(const int geb) {
    geburtstag = geb;
}

/**
 * Konstruktor for the Class Student.
 */
Student::Student(int MatNum, char* p_name, char* p_vorname, int geb) {
    matrikelNummer = MatNum;
    strncpy(name, p_name, 10);
    strncpy(vorname, p_vorname, 10);
    geburtstag = geb;
}

/**
 * Destruktor for the Class Student.
 */
Student::Student() {}

/**
 * Method to check whether two Matrikelnummern are Equal.
 */
bool Student::operator == (const Student &stu2) {
    return getMatrikelNumber() == stu2.getMatrikelNumber();
}

/**
 * Method to check whether two Matrikelnummern are not Equal
 */
bool Student::operator != (Student &stu2) {
    return getMatrikelNumber() != stu2.getMatrikelNumber();
}

/**
 * Method to check whether two Matrikelnummern are equal or smaller
 */
bool Student::operator <= (Student &stu2) {
    return getMatrikelNumber() <= stu2.getMatrikelNumber();
}

/**
 * Method to check whether two Matrikelnummern are equal or bigger
 */
bool Student::operator >= (Student &stu2) {
    return getMatrikelNumber() >= stu2.getMatrikelNumber();
}

/**
 *	Method to check whether two Matrikelnummern are smaller
 */
bool Student::operator < (Student &stu2) {
    return getMatrikelNumber() < stu2.getMatrikelNumber();
}
/**
 * Method to check whether two Matrikelnummern are equal or bigger
 */
bool Student::operator > (Student &stu2) {
    return getMatrikelNumber() > stu2.getMatrikelNumber();
}

void Student::write(ostream& ostr) {
    ostr << getMatrikelNumber() << getName() << getVorname() << getGeburtstag() << endl;
}

void Student::read(istream& istr) {
    istr >> matrikelNummer >> name >> vorname >> geburtstag;
}
