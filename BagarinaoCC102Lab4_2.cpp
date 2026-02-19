#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        int s, q;

        cout << "Enter number of students: ";
        cin >> s;

        cout << "Enter number of quizzes: ";
        cin >> q;

        double scores[100][100]; 
        double average[100];

        // Input scores
        for (int i = 0; i < s; i++) {
            cout << "\nEnter scores for Student " << i + 1 << ":\n";
            double sum = 0;
            for (int j = 0; j < q; j++) {
                cout << "Quiz " << j + 1 << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = sum / q;
        }

        cout << "\n\n========================================\n";
        cout << left << setw(5) << "Student";

        for (int j = 0; j < q; j++) {
            cout << setw(8) << ("Q" + to_string(j + 1));
        }
        cout << setw(10) << "Average" << endl;

        for (int i = 0; i < s; i++) {
            cout << setw(10) << i + 1;

            for (int j = 0; j < q; j++) {
                cout << setw(8) << scores[i][j];
            }

            cout << fixed << setprecision(2);
            cout << setw(10) << average[i] << endl;
        }
        
        cout << "\nRepeat? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}