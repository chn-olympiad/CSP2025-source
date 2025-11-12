// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector <int> a(n * m + 1, 0);
//     bool down = true, up = false;
//     for (int i = 1; i <= n * m; i++) {
//         cin >> a[i];
//     }
//     int scoreming = a[0];
//     sort(a.begin() + 1, a.end());
//     int idming = 0;
//     for (int i = 1; i <= a.size(); i++) {
//         if (a[i] == scoreming) {
//             idming = i;
//             break;
//         }
//     }
//     int id = idming; // 废
//     int x = 1, y = 1;
//     if (((id - 1) / n) % 2 == 0) {
//         x = (id - 1) / n;
//         y = n - id % n;
//         cout << x << ' ' << n - y << '\n';
//         cout << "down";
//     }
//     else if (((id - 1) / n) % 2 == 1) {
//         x = id / n;
//         y = id % n;
//         cout << x << ' ' << y << '\n';
//         cout << "UP";
//     }
//     // cout << n - id % n << ' ' << id / n;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y) {
    return y < x;
}
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector <int> a(n * m, 0);
    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
    }
    int tpscore = a[0];
    sort(a.begin(), a.end(), cmp);
    vector <vector <int> > seat(n, vector <int> (m, 0));
    bool down = true, up = false;
    // int x = 1, y = n;
    // for (int i = 0; i < n * m; i++) {
    //     if ((i / n) % 2 == 0 && i % n == n - 1) {
    //         down = true;
    //         up = false;
    //         y = 1;
    //         x++;
    //     }
    //     else if ((i / n) % 2 == 1 && i % n == 0) {
    //         down = false;
    //         up = true;
    //         x++;
    //         y = n;
    //     }
    //     else if (down) {
    //         y--;
    //     }
    //     else if (up) {
    //         y++;
    //     }
    //     cout << a[i] << ' ' << x << ' ' << y << '\n';
    //     if (a[i] == tpscore) {
    //         cout << a[i] << '\n';
    //         cout << x << ' ' << n - y << '\n';
    //         return 0;
    //     }
    // }
    int iter = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                seat[j][i] = a[iter];
                iter++;
            }
        }
        else if (i % 2 == 1) {
            for (int j = m - 1; j >= 0; j--) {
                seat[j][i] = a[iter];
                iter++;
            }
        }
    }
    int ansx = 0, ansy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << seat[i][j] << ' ';
            // cout << i + 1 << ' ' << j + 1 << '\n';
            if (seat[i][j] == tpscore) {
                cout << j + 1 << ' ' << i + 1 << '\n';
                return 0;
            }
        }
    }
    return 0;
}