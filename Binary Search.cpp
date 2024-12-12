#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll_no;
    string name;
    float SGPA;
};

int binarySearch(Student arr[], int n, string key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid].name == key) return mid;
        else if (arr[mid].name < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void display(Student s) {
    cout << s.roll_no << " " << s.name << " " << s.SGPA << endl;
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

    string searchName;
    cout << "Enter name of student to search: ";
    cin >> searchName;

    int index = binarySearch(students, n, searchName);
    if (index != -1) {
        display(students[index]);
    } else {
        cout << "Student not found!" << endl;
    }
    return 0;
}
