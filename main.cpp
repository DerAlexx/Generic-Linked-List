//============================================================================
// Name        : main.cpp
// Author      : Alexander M. Westphal / Paul Schröder
// Version     : Version 1.0
// Copyright   : Alexander M. Westphal / Paul Schröder
// Description : Main Program
// Compiler and C++ Version: GNU GCC / C++11 Standard
//============================================================================

#include <iostream>
#include "student.h"
#include "student.cpp"
#include "CursorList.h"

CursorList<Student> curs;

int input();
void createStudent();
void deleteStudent();
void createStudentBeforePosition();
void deleteStudentWithStartAndStop();


int main() {
    int eingabe = -1;
    while (eingabe != 0){
        cout << "Aktuell passen noch " << curs.array_size_start - curs.get_counter() << " Studenten in die Liste"<< endl << "Studenten: " << endl;
        for(CursorList<Student>::iterator it = curs.begin(); it != CursorList<Student>::iterator(-1, curs.arr); ++it) {
            std::cout << it.m_index << " " << *it << std::endl;

        }

        eingabe = input();
        switch(eingabe){
            case 1:
                createStudent();
                break;
            case 2:
                createStudentBeforePosition();
                break;
            case 3:
                curs.pop_front();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                deleteStudentWithStartAndStop();
                break;
            case 6:
                std::cout << curs.front() << std::endl;
                break;
            case 7:
                std::cout << curs.get_counter() << std::endl;
                break;
            case 8:
                eingabe = 0;
                break;
            default:
                std::cout << "falsche eingabe";
                break;
        }
    }
    return 0;
}

/**
 * Inputmenu for the user to enter a option on the commandline and execute this point.
 * @return will return the entered value as Integer.
 */
int input() {
    using namespace std;
    int eingabe;
    cout << "Menue:" << endl;
    cout << "(1) Student hinzufuegen am Anfang der Liste" << endl;
    cout << "(2) Student hinzufuegen an bestimmter Stelle" << endl;
    cout << "(3) Student entfernen am Anfang der Liste" << endl;
    cout << "(4) Student an bestimmter Stelle entfernen " << endl;
    cout << "(5) mehrere Studenten an bestimmter Stelle entfernen" << endl;
    cout << "(6) Wie lautet der erste Student in der Liste " << endl;
    cout << "(7) aktuelle Studentenanzahl in CursorList" << endl;
    cout << "(8) Fertig" << endl;
    cout << "Eingabe: ";
    cin >> eingabe;
    return eingabe;
}


/**
 * Method to create a Student and put it in the Datastructur.
 */
void createStudent(){
    using namespace std;
    int i,k;
    char u[10],j[10];
    cout << "Geben sie eine Matrikelnummer, einen Geburtstag der Form (04021998) sowie einen Namen und einen Vornamen ein" << endl;
    cout << "Beispiel: 666 06066666 Johanny Satan \n";
    cin >> i >> k >> u >> j;
        Student abc(i, u, j ,k);
        try {
            curs.push_front(abc);
        } catch (...) {
            cout << "Error Occured Data Struct is full" << endl;
        }
}

/**
 * Method to delete a Student.
 */
void deleteStudent(){
    using namespace std;
    int position;
    cout << "Geben sie die Position eines Studenten ein, der geloescht werden soll" << endl;
    cin >> position;
        try {
            curs.erase(CursorList<Student>::ListIterator(position, curs.arr)); //CursorList<Student>::ListIterator(position, curs.arr)
        } catch (...) {
            cout << "Error Occured Data Struct is full" << endl;
        }
}

/**
 * Method to delete a bunch of Students from a start until a specefied end.
 */
void deleteStudentWithStartAndStop(){
    using namespace std;
    int start, stop;
    cout << "Geben Sie einen Start und Endpunkt ein, in dem alle Studenten geloescht werden" << endl;
    cin >> start >> stop;
        try {
            curs.erase(CursorList<Student>::ListIterator(start, curs.arr), CursorList<Student>::ListIterator(stop, curs.arr));
        } catch (...) {
            cout << "Error Occured Data Struct is full" << endl;
        }
}


/**
 * Create a Student at a specified position.
 */
void createStudentBeforePosition(){
    using namespace std;
    int i,k, position;
    char u[10],j[10];
    cout << "Geben sie eine Matrikelnummer, einen Geburtstag der Form (40298 fuer 4.02.1998), einen Namen, einen Vornamen und eine Position ein" << endl;
    cin >> i >> k >> u >> j >> position;
    Student abc(i, u, j ,k);
        try {
            curs.insert(CursorList<Student>::ListIterator(position, curs.arr), abc);
        } catch (...) {
            cout << "Error Occured Data Struct is full" << endl;
        }
}