#include<bits/stdc++.h>
#define PII pair<int,int>
#define pb push_back
using namespace std;
const int Maxn = 2e5 + 10;
string s[Maxn][2], t[Maxn][2];
void work(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> s[i][1] >> s[i][2];
        // cout << s[i][1][0] << endl;
    }
    for(int i = 1; i <= q; i++){
        cin >> t[i][1] >> t[i][2];
    }
    for(int i = 1; i <= q; i++){
        int ans = 0;
        for(int j = 1; j <= n; j++){
            int sz = s[j][1].size();
            for(int p = 0; p + sz <= t[i][1].size(); p++){
                string tmp = t[i][1], tmp2 = t[i][2];
                int fl = 1;
                for(int c = p; c <= p + sz - 1; c++) if(tmp[c] != s[j][1][c-p]) fl =0;
                if(!fl) continue;
                for(int c = p; c <= p + sz - 1; c++) tmp[c] = s[j][2][c - p];
                if(tmp == tmp2) ans++;
            }
        }
        cout << ans << endl;
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--){
        work();
    }
}
/*

所以，要怎样才能获得一个好的结果呢。

状态奇差。

输麻了。

还有期中考试。

救命。


*/