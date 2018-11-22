//============================================================================
// Name        : main.cpp
// Author      : Alexander M. Westphal / Paul Schröder
// Version     : Version 1.0
// Copyright   : Alexander M. Westphal / Paul Schröder
// Description : Main Program
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

    Student julien = Student(111 , "Julien", "Peuker",  90909);
    Student klaus = Student(999  ,"Klaus", "Boss", 11111);
    Student thomas = Student(815, "Thomas", "Pumper", 7777);
    Student reneEgo10 = Student(666, "a", "Lauch", 6666);


    CursorList <Student> list;


    cout << "startdata " <<list.start_data << endl;
    cout <<"startfree "<< list.start_free << endl;
    cout << "Index:0 "<< list.arr[0].data.getName() << " |prev: " << list.arr[0].prev << " |next: " << list.arr[0].next << endl;
    cout<< "Index:1 " << list.arr[1].data.getName() << " |prev: " << list.arr[1].prev << " |next: " << list.arr[1].next << endl;
    cout << "Index:2 "<< list.arr[2].data.getName() << " |prev: " << list.arr[2].prev << " |next: " << list.arr[2].next << endl;
    cout << "Index:3 "<< list.arr[3].data.getName() << " |prev: " << list.arr[3].prev << " |next: " << list.arr[3].next << endl;
    cout << "Index:4 "<< list.arr[4].data.getName() << " |prev: " << list.arr[4].prev << " |next: " << list.arr[4].next << endl;

    list.push_front(klaus);
    list.push_front(reneEgo10);
    list.push_front(thomas);

    cout << "startdata " <<list.start_data << endl;
    cout <<"startfree "<< list.start_free << endl;
    cout << "Index:0 "<< list.arr[0].data.getName() << " |prev: " << list.arr[0].prev << " |next: " << list.arr[0].next << endl;
    cout<< "Index:1 " << list.arr[1].data.getName() << " |prev: " << list.arr[1].prev << " |next: " << list.arr[1].next << endl;
    cout << "Index:2 "<< list.arr[2].data.getName() << " |prev: " << list.arr[2].prev << " |next: " << list.arr[2].next << endl;
    cout << "Index:3 "<< list.arr[3].data.getName() << " |prev: " << list.arr[3].prev << " |next: " << list.arr[3].next << endl;
    cout << "Index:4 "<< list.arr[4].data.getName() << " |prev: " << list.arr[4].prev << " |next: " << list.arr[4].next << endl;

    //list.insert(CursorList<Student>::ListIterator(2, list.arr), julien);
    list.erase(CursorList<Student>::ListIterator(2, list.arr), CursorList<Student>::ListIterator(0, list.arr));



    cout << "startdata " <<list.start_data << endl;
    cout <<"startfree "<< list.start_free << endl;
    cout << "Index:0 "<< list.arr[0].data.getName() << " |prev: " << list.arr[0].prev << " |next: " << list.arr[0].next << endl;
    cout<< "Index:1 " << list.arr[1].data.getName() << " |prev: " << list.arr[1].prev << " |next: " << list.arr[1].next << endl;
    cout << "Index:2 "<< list.arr[2].data.getName() << " |prev: " << list.arr[2].prev << " |next: " << list.arr[2].next << endl;
    cout << "Index:3 "<< list.arr[3].data.getName() << " |prev: " << list.arr[3].prev << " |next: " << list.arr[3].next << endl;
    cout << "Index:4 "<< list.arr[4].data.getName() << " |prev: " << list.arr[4].prev << " |next: " << list.arr[4].next << endl;
    cout << "Index:4 "<< list.arr[29].data.getName() << " |prev: " << list.arr[29].prev << " |next: " << list.arr[29].next << endl;

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
    cout << "(7) aktuelle Studentenanzahl in CursorList" << "/n" << endl;
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
            curs.erase(CursorList<Student>::ListIterator(position, curs.arr));
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
            curs.erase(::find(curs.begin(), curs.end(), curs.get_value(start)), ::find(curs.begin(), curs.end(), curs.get_value(stop)));
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
            curs.insert(::find(curs.begin(), curs.end(), curs.get_value(position)), abc);
        } catch (...) {
            cout << "Error Occured Data Struct is full" << endl;
        }
}