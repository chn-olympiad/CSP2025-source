#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    freopen("club.in", "w", stdout);
    mt19937_64 gen(time(0));
    uniform_int_distribution<long long> T(1, 5);
    uniform_int_distribution<long long> N(2, 1e5);
    uniform_int_distribution<long long> A(0, 2e4);
    int t = T(gen)
    cout << t << "\n";
    for (int i = 1; i <= t; i++) {
        int n = N(gen) / 2 * 2;
        cout << n << "\n";
        for (int j = 1; j <= n; j++) cout << A(gen) << " " << A(gen) << " " << A(gen) << "\n";
    }
    return 0;
}
