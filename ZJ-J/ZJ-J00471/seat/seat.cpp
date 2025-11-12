#include <bits/stdc++.h>
using namespace std;

vector<int> scores;
int n, m, c, r, a1, pos;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    scores.resize(n * m + 1);

    for (int i = 1; i <= n * m; i++) cin >> scores[i];
    a1 = scores[1];

    sort(scores.begin(), scores.end(), [](int x, int y){ return x > y; });

    pos = find(scores.begin() + 1, scores.end(), a1) - scores.begin();

    c = pos / n + 1;

    if (c % 2 == 1) {
        r = pos % n + 1;
    } else {
        r = n - pos % n;
    }

    cout << c << " " << r;

    fclose(stdin);
    fclose(stdout);

    return 0;
}