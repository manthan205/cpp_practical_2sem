#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string name;
    int score;
};

bool compare_scores(const Student& a, const Student& b) {
    return a.score > b.score;
}

int main() {
    vector<Student> students;
    string name;
    int score;

    cout << "Enter student names and scores (type 'end' to stop):\n";

    while (true) {
        cout << "Name: ";
        cin >> name;
        if (name == "end") {
            break;
        }

        cout << "Score: ";
        cin >> score;

        students.push_back({name, score});
    }

    sort(students.begin(), students.end(), compare_scores);

    cout << "\nRanked Student List:\n";
    int rank = 1;
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << rank << ". " << it->name << " - " << it->score << "\n";
        ++rank;
    }

    cout<<endl<<endl;
    cout << "24CE103_Manthan Rangpariya" << endl;
    return 0;
}
