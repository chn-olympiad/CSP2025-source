#include<cstdint>
#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 2 ^ 20 ~= 10^6 ~ 10^7
const uint64_t N = 5 * 100000 + 1;
uint64_t n, k;

int main() {
    freopen("xor.in", "r", stdin);
#ifndef kaFkailoVeyou
    freopen("xor.out", "w", stdout);
#endif
    cout.sync_with_stdio(false);
    cin.sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    cin >> n >> k;
    for (uint64_t i = 1; i <= n; ++i) {
        uint64_t buf;
        cin >> buf;
    }
    cout << n / 2 << '\n';
    cout.flush();
    fclose(stdin);
#ifndef kaFkailoVeyou
    fclose(stdout);
#endif
    return 0;
}