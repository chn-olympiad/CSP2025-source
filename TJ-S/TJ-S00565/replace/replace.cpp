#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

int n, m;
char a[5000005], b[5000005];
map<int, int>mp;
const int P = 998244153;
const int P2 = 99833;
const int PP = 928244153;
const int PP2 = 95833;
const int P3 = 938244787;
int p[5000005], pp[5000005], p2[5000005], p3[5000005], ur[200005], ue, lst[30], nxt[5000005];

struct qq {
    int u, l, ed;
} o[200005];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        scanf("%s%s", a + 1, b + 1);
        int u = strlen(a + 1);
        ull uu = 0, dd = 0;
        for(int j = 1; j <= u; j++) {
            uu = (1ll * uu * P2 + a[j]) % P;
            dd = (1ll * dd * PP2 + b[j]) % PP;
        }
        ll su = 1ll * (uu+PP2) * (dd + P2) % P3;
        o[i] = {su, u, a[u] - 'a'};
    }
    sort(o + 1, o + n + 1, [](qq x, qq y) {return x.l > y.l;});
    p[0] = 1, pp[0] = 1;
    for(int i = 1; i <= 5000000; i++)p[i] = 1ll * p[i - 1] * P2 % P;
    for(int i = 1; i <= 5000000; i++)pp[i] = 1ll * pp[i - 1] * PP2 % PP;
    for(int i = 1; i <= m; i++) {
        scanf("%s%s", a + 1, b + 1);
        int u = strlen(a + 1);
        int u2 = strlen(b + 1);
        if(u != u2)printf("0\n");
        else {
            //if(i==26062){
            //    cout<<"";
            //}
            ll ans = 0;
            int tl = 0, tr = 0;
            memset(lst, 0x3f, sizeof(lst));
            for(int j = 1; j <= u; j++)if(a[j] != b[j])tr = j;
            for(int j = u; j >= 1; j--){
                if(a[j] != b[j])tl = j;
                nxt[j] = lst[a[j] - 'a'], lst[a[j] - 'a'] = j;
            }
            for(int i = 1; i <= u; i++) {
                p2[i] = (1ll * p2[i - 1] * P2 + a[i]) % P;
                p3[i] = (1ll * p3[i - 1] * PP2 + b[i]) % PP;
            }
            for(int j = 1; j <= n; j++) {
                if(o[j].l < tr - tl + 1)break;
                for(int k = max(o[j].l, tr); k <= min(u, tl + o[j].l - 1);) {
                    if(a[k] - 'a'!=o[j].ed){
                        k++;
                        continue;
                    }
                    int ut = (p2[k] - 1ll * p2[k - o[j].l] * p[o[j].l] % P + P) % P;
                    int ud = (p3[k] - 1ll * p3[k - o[j].l] * pp[o[j].l] % PP + PP) % PP;
                    ll su = 1ll * (ut+PP2) * (ud + P2) % P3;
                    if(su == o[j].u) ans++;
                    k = nxt[k];
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}
/*
for(int i = 1;i<=u;i++){
                p2[i] = (p2[i - 1] * P2 + a[i]) % P;
                p3[i] = (p3[i - 1] * P2 + b[i]) % P;
            }
*/

