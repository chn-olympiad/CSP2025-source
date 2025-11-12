#include <bits/stdc++.h>
using namespace std;
string a[200005],b[200005];
string c[200005],d[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 1;i <= q;i++){
        cin >> c[i] >> d[i];
    }
    for(int i = 1;i <= q;i++){
        int ans = 0;
        for(int j = 1;j <= n;j++){
            for(int k = 0;k + a[j].size() - 1 < c[i].size();k++){
                string sb = c[i].substr(k,a[j].size());
                string sc = c[i].substr(0,k) + b[j] + c[i].substr(k + a[j].size(),c[i].size() - k - a[j].size());
                //cout << sc << " ";
                if(sb == a[j] && sc == d[i])ans++;
            }
        }
        cout << ans << '\n';
    }





    return 0;
}