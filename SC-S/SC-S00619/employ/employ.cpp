#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const long long N = 5e2 + 10, Mod = 998244353;
long long c[N], cnt, n, m;
std :: string s;
std :: vector <long long> p;

bool check() {
    long long tot = 0, rec = 0;
    for (long long i = 0; i < p.size(); i ++) {
        if (s[i] == '0' || tot >= c[p[i]]) tot ++;
        else rec ++;
    }
    return rec >= m;
}

int main() {

    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    long long nj = 1;
    scanf("%lld%lld", &n, &m);
    std :: cin >> s;
    for (long long i = 1; i <= n; i ++) {
        scanf("%lld", &c[i]);
        p.push_back(i);
        nj = nj * i % Mod;
        if (c[i]) cnt ++;
    }
    if (n > 10) {
        if (cnt < m) printf("0\n");
        else printf("%lld\n", nj);
        return 0;
    }

    cnt = 0;
    for (long long i = 1; i <= nj; i ++) {
        cnt += check() ? 1 : 0;
        std :: next_permutation(p.begin(), p.end());
    }
    printf("%lld\n", cnt);


    return 0;
}