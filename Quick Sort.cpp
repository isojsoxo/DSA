#include <iostream>
using namespace std;

struct Student {
    int roll_no;
    string name;
    float SGPA;
};

int partition(Student arr[], int low, int high) {
    float pivot = arr[high].SGPA;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].SGPA >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void displayTop10(Student arr[], int n) {
    for (int i = 0; i < n && i < 10; i++) {
        cout << arr[i].roll_no << " " << arr[i].name << " " << arr[i].SGPA << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student students[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter roll_no, name, and SGPA for student " << i + 1 << ": ";
        cin >> students[i].roll_no >> students[i].name >> students[i].SGPA;
    }

    quickSort(students, 0, n - 1);
    cout << "\nTop 10 students sorted by SGPA: \n";
    displayTop10(students, n);
    return 0;
}
