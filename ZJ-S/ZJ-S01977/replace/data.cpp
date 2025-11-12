#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("replace.in", "w", stdout);
    auto gen = [&](string &s, int len) {
        while(len--) {
            s.push_back(rand() % 26 + 'a');
        }
    };
    int n = 1, q = 1, L1 = 1e6, L2 = 5e5, L3 = 1e6;
    string x, y, Y, z;
    gen(x, L1), gen(y, L2), gen(Y, L2), gen(z, L3);
    cout << n << ' ' << q << '\n' << x + y + z << ' ' << x + Y + z << '\n' << x + y + z << ' ' << x + Y + z << '\n';
    return 0;
}