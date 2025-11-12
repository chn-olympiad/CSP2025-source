#include<cstdint>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

uint64_t mat[11][11];
uint64_t n, m;

struct inputImpl {
    bool is_my;
    uint64_t score;
};

int main() {
    freopen("seat.in", "r", stdin);
#ifndef kaFkailoVeyou
    freopen("seat.out", "w", stdout);
#endif
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    memset(mat, 0x00, sizeof(mat));
    cin >> n >> m;
    uint64_t size = n * m;
    vector<inputImpl> v(size);
    for (uint64_t i = 0; i < size; ++i) {
        if (i == 0) {
            v[i].is_my = true;
        } else {
            v[i].is_my = false;
        }
        cin >> v[i].score;
    }
    sort(v.begin(), v.end(), [](inputImpl a, inputImpl b) {
        return a.score > b.score;
    });
    for (uint64_t i = 0; i < size; ++i) {
        if (v[i].is_my == false) {
            continue;
        }
        uint64_t id = i + 1;
        uint64_t r1 = (id + n - 1) / m;
        uint64_t r2 = id - (r1 - 1) * n;;
        if (r1 % 2 == 0) {
            r2 = n - r2 + 1;
        } else if (r1 % 2 == 1) {
            // nothing to do.
        } else {
            // why ???
        }
        cout << r1 << ' ' << r2 << '\n';
        break;
    }
    cout.flush();
    fclose(stdin);
#ifndef kaFkailoVeyou
    fclose(stdout);
#endif
    return 0;
}