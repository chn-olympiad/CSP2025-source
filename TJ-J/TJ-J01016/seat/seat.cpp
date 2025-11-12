#include <bits/stdc++.h>
using namespace std;

int score[225];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> score[i];
    }

    int me = score[1], pai;
    sort(score + 1, score + (n * m) + 1, greater<int>());
    for (int i = 1; i <= n * m; i++) {
        if (score[i] == me) {
            pai = i;
            break;
        }
    }

    int mod = pai % n;
    int shang = pai / n;
    if (mod == 0) {
        if (shang % 2 == 0) {
            cout << shang << " " << 1 << endl;
        } else {
            cout << shang << " " << n << endl;
        }
    } else {
        if (shang % 2 == 0) {
            cout << shang + 1 << " " << mod << endl;
        } else {
            cout << shang + 1 << " " << n - mod + 1 << endl;
        }
    }
    return 0;
}

