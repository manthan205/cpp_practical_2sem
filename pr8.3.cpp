
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    vector<int> transactionIDs = {101, 203, 101, 405, 203, 506, 405};

    set<int> uniqueTransactionIDs(transactionIDs.begin(), transactionIDs.end());

    cout << "Unique Transaction IDs (sorted): ";
    for (const int& id : uniqueTransactionIDs) {
        cout << id << " ";
    }
    cout << endl;

    cout << "24CE103_Manthan Rangpariya"<<endl;

    return 0;
}

