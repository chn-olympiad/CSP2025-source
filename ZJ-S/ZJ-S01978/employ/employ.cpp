#include<bits/stdc++.h>
using namespace std;
const int N = 510, mod = 998244353;
string st;
int n, m, a[N], ans;
void add(int &x, int y){x = (x + y) % mod;}
namespace subtask1{
    int f[1 << 18][20];
    void solve(){
        f[0][0] = 1;
        for(int s = 0; s < (1 << n) - 1; s++){
            int len = __builtin_popcount(s);
            for(int i = 1; i <= n; i++){
                if(!((s >> (i - 1)) & 1)){
                    for(int j = 0; j <= len; j++){
                        int s1 = s ^ (1 << (i - 1));
                        if(st[len + 1] == '0' || (len - j) >= a[i]) add(f[s1][j], f[s][j]);
                        else add(f[s1][j + 1], f[s][j]);
                    }

                }
            }
        }
        for(int i = m; i <= n; i++) add(ans, f[(1 << n) - 1][i]);
        cout << ans << endl;
    }
}
int main(){
    // freopen("example/employ2.in", "r", stdin);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> st;
    st = " " + st;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(n <= 18) subtask1::solve();
    else cout << 0 << endl;
    return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/