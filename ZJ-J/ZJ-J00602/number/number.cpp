#include <bits/stdc++.h>

using namespace std;

string s;
int numberCount = 0;
int numbers[1000010];

bool myCompare (int x, int y) {
    return x > y;
}

int main () {
    freopen ("number.in", "r", stdin);
    freopen ("number.out", "w", stdout);

    cin >> s;
    int length = s.size ();
    for (int i = 0; i < length; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            ++numberCount;
            numbers[numberCount] = s[i] - '0';
        }
    }

    sort (numbers + 1, numbers + numberCount + 1, myCompare);

    for (int i = 1; i <= numberCount; ++i) {
        cout << numbers[i];
    }
    cout << endl;

    fclose (stdin);
    fclose (stdout);
    return 0;
}