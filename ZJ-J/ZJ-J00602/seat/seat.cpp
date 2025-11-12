#include <bits/stdc++.h>
using namespace std;

int studentCount;
int lnCount, colCount;
int myScore;
int mySeatNumber;
int mySeatLn, mySeatCol;
int studentScores[1010];

bool myCompare (int x, int y) {
    return x > y;
}

int main () {
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);

    cin >> lnCount >> colCount;

    studentCount = lnCount * colCount;

    for (int i = 1; i <= studentCount; ++i) {
        cin >> studentScores[i];
    }
    myScore = studentScores[1];

    sort (studentScores + 1, studentScores + studentCount + 1, myCompare);

    for (int i = 1; i <= studentCount; ++i) {
        if (studentScores[i] == myScore) {
            mySeatNumber = i;
        }
    }

    mySeatCol = floor((mySeatNumber - 1) / lnCount * 1.0) + 1;
    if (mySeatCol % 2) {
        mySeatLn = (mySeatNumber - 1) % lnCount + 1;
    } else {
        mySeatLn = lnCount - (mySeatNumber - 1) % lnCount;
    }
    

    cout << mySeatCol << ' ' << mySeatLn << endl;

    fclose (stdin);
    fclose (stdout);
    return 0;
}