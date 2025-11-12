#include<bits/stdc++.h>
using namespace std;

int a[1000];

int main () {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cin >> a[n * m];
    int c, r;
    if (n == 2 && m == 2) {
        if (a[1] > a[2] && a[1] > a[3] && a[1] > a[4]) {
            c = 1;
            r = 1;
            cout << c << " " << r << endl;
        }
        else {
            if ((a[1] < a[2] && a[1] > a[3] && a[1] > a[4]) || (a[1] > a[2] && a[1] < a[3] && a[1] > a[4]) || (a[1] > a[2] && a[1] > a[3] && a[1] < a[4])) {
                c = 1;
                r = 2;
                cout << c << " " << r << endl;
            }
            else {
                if ((a[1] < a[2] && a[1] < a[3] && a[1] > a[4]) || (a[1] > a[2] && a[1] < a[3] && a[1] < a[4]) || (a[1] < a[2] && a[1] > a[3] && a[1] < a[4])) {
                    c = 2;
                    r = 2;
                    cout << c << " " << r << endl;
                }
                else {
                    if (a[1] < a[2] && a[1] < a[3] && a[1] < a[4]) {
                        c = 2;
                        r = 1;
                        cout << c << " " << r << endl;
                    }
                }
            }
        }
    }
    else {
        if (n == 1 && m == 1) {
        c = 1;
        r = 1;
        cout << c << " " <<   r << endl;
        }
        else {
            if (n == 1) {
                max(a[1], a[m * n]);
                c = 1;
                r = 1;
                cout << c << " " << r << endl;
            }
        }  
    }
    return 0;
}