#include <iostream>
#include <vector>
using namespace std;

int main() {
    char again;

    do {
        int students, days;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of school days: ";
        cin >> days;

        vector<vector<int>> attendance(students, vector<int>(days));

        
        for (int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << " attendance:\n";
            for (int j = 0; j < days; j++) {
                cout << "Day " << j + 1 << " (1=Present, 0=Absent): ";
                cin >> attendance[i][j];
            }
        }

        
        cout << "\nStudent ";
        for (int d = 0; d < days; d++)
            cout << "D" << d + 1 << " ";
        cout << "Total Percent Remarks\n";

        
        for (int i = 0; i < students; i++) {
            int total = 0;

            cout << i + 1 << "       ";

            for (int j = 0; j < days; j++) {
                cout << attendance[i][j] << " ";
                total += attendance[i][j];
            }

            double percent = (double)total / days * 100;
            string remark = (percent < 50) ? "DRP" : "OK";

            cout << total << "     ";
            cout << percent << "%     ";
            cout << remark << endl;
        }

        cout << "\nRun again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}