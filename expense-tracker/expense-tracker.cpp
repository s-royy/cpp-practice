#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Expense {
    double amount;
    string category;
    string description;
};

const string FILE_NAME = "expenses.txt";

vector<Expense> loadExpenses() {
    vector<Expense> expenses;
    ifstream file(FILE_NAME);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string amount, category, description;

        getline(ss, amount, ',');
        getline(ss, category, ',');
        getline(ss, description, ',');

        expenses.push_back({stod(amount), category, description});
    }

    return expenses;
}

void saveExpenses(const vector<Expense>& expenses) {
    ofstream file(FILE_NAME);
    for (const auto& e : expenses) {
        file << e.amount << "," << e.category << "," << e.description << "\n";
    }
}

void addExpense(vector<Expense>& expenses) {
    Expense e;

    cout << "Enter amount: ";
    cin >> e.amount;
    cin.ignore();

    cout << "Enter category: ";
    getline(cin, e.category);

    cout << "Enter description: ";
    getline(cin, e.description);

    expenses.push_back(e);
    saveExpenses(expenses);

    cout << "Expense added.\n";
}

void viewExpenses(const vector<Expense>& expenses) {
    if (expenses.empty()) {
        cout << "No expenses found.\n";
        return;
    }

    double total = 0;
    int i = 1;

    for (const auto& e : expenses) {
        cout << i++ << ". " << e.amount << " | " << e.category << " | " << e.description << "\n";
        total += e.amount;
    }

    cout << "\nTotal: " << total << "\n";
}

int main() {
    vector<Expense> expenses = loadExpenses();

    while (true) {
        cout << "\n--- Expense Tracker ---\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Exit\n";

        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice == 1) {
            addExpense(expenses);
        } else if (choice == 2) {
            viewExpenses(expenses);
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
