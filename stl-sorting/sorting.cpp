#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int marks;
};

bool compare(Student a, Student b) {
    return a.marks > b.marks;
}

int main() {
    vector<Student> students = {
        {"Amit", 85},
        {"Riya", 92},
        {"John", 78},
        {"Sara", 88}
    };

    sort(students.begin(), students.end(), compare);

    cout << "Students sorted by marks (descending):\n";
    for (const auto& s : students) {
        cout << s.name << " - " << s.marks << endl;
    }

    return 0;
}
