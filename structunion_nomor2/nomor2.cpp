#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NO_OF_STUDENTS = 20;

struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// a. Fungsi untuk membaca data siswa
void getData(studentType sList[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Masukkan Nama Depan, Nama Belakang, dan Nilai untuk siswa ke-" << i + 1 << ": ";
        cin >> sList[i].studentFName >> sList[i].studentLName >> sList[i].testScore;
    }
}

// b. Fungsi untuk menentukan grade berdasarkan nilai
void assignGrade(studentType sList[], int size) {
    for (int i = 0; i < size; i++) {
        int score = sList[i].testScore;

        if (score >= 90)
            sList[i].grade = 'A';
        else if (score >= 80)
            sList[i].grade = 'B';
        else if (score >= 70)
            sList[i].grade = 'C';
        else if (score >= 60)
            sList[i].grade = 'D';
        else
            sList[i].grade = 'E';
    }
}

// c. Fungsi untuk mencari nilai tertinggi
int highestScore(const studentType sList[], int size) {
    int max = sList[0].testScore;
    for (int i = 1; i < size; i++) {
        if (sList[i].testScore > max)
            max = sList[i].testScore;
    }
    return max;
}

// d. Fungsi untuk mencetak nama siswa dengan nilai tertinggi
void printHighest(const studentType sList[], int size, int maxScore) {
    cout << "\nSiswa dengan nilai tertinggi (" << maxScore << "):\n";
    for (int i = 0; i < size; i++) {
        if (sList[i].testScore == maxScore) {
            cout << sList[i].studentLName << ", " << sList[i].studentFName << endl;
        }
    }
}

// Fungsi untuk mencetak seluruh data siswa
void printData(const studentType sList[], int size) {
    cout << left << setw(20) << "Nama"
         << setw(15) << "Nilai"
         << "Grade" << endl;
    cout << "-----------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << left << setw(20) 
             << (sList[i].studentLName + ", " + sList[i].studentFName)
             << setw(15) << sList[i].testScore
             << sList[i].grade << endl;
    }
}

int main() {
    studentType studentList[NO_OF_STUDENTS];

    getData(studentList, NO_OF_STUDENTS);
    assignGrade(studentList, NO_OF_STUDENTS);
    printData(studentList, NO_OF_STUDENTS);

    int maxScore = highestScore(studentList, NO_OF_STUDENTS);
    printHighest(studentList, NO_OF_STUDENTS, maxScore);

    return 0;
}
