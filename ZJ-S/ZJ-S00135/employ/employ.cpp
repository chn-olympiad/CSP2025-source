#include<bits/stdc++.h>
#define int long long
#define FL(i, a, b) for(int i = (a), i##end = (b); i <= i##end; ++i)
#define FR(i, a, b) for(int i = (a), i##end = (b); i >= i##end; --i)
using namespace std;
constexpr int N = 1e6 + 10;
int n, m, c[N], p[N], ans;
char s[N];
void ___(){
    cin >> n >> m >> s + 1;
    FL(i, 1, n)cin >> c[i], p[i] = i;
    do{
        int res = 0, cnt = 0;
        FL(id, 1, n){
            int i = p[id];
            if(c[i] <= res || s[id] == '0')res++;
            else cnt++;
            if(cnt >= m)break;
        }
        ans += (cnt >= m);
    }while(next_permutation(p + 1, p + 1 + n));
    cout << ans;
}
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--)___();
    return 0;
}