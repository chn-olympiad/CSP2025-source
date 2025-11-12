#include <bits/stdc++.h>

using namespace std;
long long T, n;
const long long N = 1e5 + 10;
struct Node {
    long long id;
    long long a[5];
} sat[N];
long long chs[N];
long long cnt, siz[4];
struct Val {
    long long id, val;
} v[N];
long long les(long long x) {
    if(x == 1) return 3;
    if(x == 2) return 1;
    if(x == 3) return 2;
    return -1;
}
long long ri(long long x) {
    if(x == 1) return 2;
    if(x == 2) return 3;
    if(x == 3) return 1;
    return -1;
}
bool cmp(Val a, Val b) {
    return a.val < b.val;
}
void work() {
    scanf("%lld", &n);
    cnt = 0;
    siz[1] = siz[2] = siz[3] = 0;
    long long ans = 0;
    for(long long i = 1; i <= n; i++) {
        scanf("%lld%lld%lld", &sat[i].a[1], &sat[i].a[2], &sat[i].a[3]);
        for(long long j = 1; j <= 3; j++) 
            if(sat[i].a[chs[i]] < sat[i].a[j])
                chs[i] = j;
        siz[chs[i]]++, ans += sat[i].a[chs[i]];
    }
    long long op = 0;
    if(siz[1] > n / 2) op = 1;
    if(siz[2] > n / 2) op = 2;
    if(siz[3] > n / 2) op = 3;
    for(long long i = 1; i <= n; i++)
        if(chs[i] == op)
            v[++cnt] = {i, min(sat[i].a[op] - sat[i].a[les(op)], sat[i].a[op] - sat[i].a[ri(op)])};
    sort(v + 1, v + cnt + 1, cmp);
    long long out = siz[op] - n / 2;
    for(long long i = 1; i <= out; i++)
        ans -= v[i].val;
    printf("%lld\n", ans);
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%lld", &T);
    while(T--) work();
}