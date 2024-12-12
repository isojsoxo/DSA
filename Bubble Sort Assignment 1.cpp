#include <iostream>
using namespace std;

struct Student {
    int roll_no;
    string name;
    float SGPA;
};

void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll_no > arr[j + 1].roll_no) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void display(Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i].roll_no << " " << arr[i].name << " " << arr[i].SGPA << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter roll_no, name, 
