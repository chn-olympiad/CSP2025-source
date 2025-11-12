#include<bits/stdc++.h>
using namespace std;

int n, q, ans;
char aa;
string s[1005][3], t[1005][3];

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> s[i][1] >>s[i][2];
    }
    for(int i = 1;i <= q;i++){
        cin >> t[i][1] >>t[i][2];
    }
    // for(int i = 1;i <= n;i++){
    //     cout<<s[i][1]<<' '<<s[i][2]<<'\n';
    // }
    // for(int i = 1;i <= q;i++){
    //     cout <<t[i][2]<<' '<<t[i][2]<<'\n';
    // }
    for(int l = 1;l <= q;l++){
        // cout<<1<<'\n';
        ans = 0;
        string ss = t[l][1];
        int len = ss.size();
        for(int i = 0;i < len;i++){
            for(int j = i;j < len;j++){
                string xx = "", tt = "", zz = "";
                for(int k = 0;k < i;k++) xx = xx + ss[k];
                for(int k = j + 1;k < len;k++) zz = zz + ss[k];
                for(int k = i;k <= j;k++){
                    tt = tt + ss[k];
                }
                // cout<<xx<<' '<<tt<<' '<<zz<<'\n';
                for(int k = 1;k <= n;k++){
                    if(tt == s[k][1]){
                        if(xx + s[k][2] + zz == t[l][2]) ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}