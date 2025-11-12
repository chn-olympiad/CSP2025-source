#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1E5 + 5;
int n,T,a[N][3],op[N];
void los(){
    cin >> n; vector<int> cnt(3);
    ll ans = 0;
    for(int i = 1;i <= n;i ++) 
        cin >> a[i][0] >> a[i][1] >> a[i][2],cnt[op[i] = max_element(a[i],a[i]+3) - a[i]] ++,
        ans += a[i][op[i]];
    vector<int> dif;
    int o = max_element(cnt.begin(),cnt.end()) - cnt.begin();
    for(int i = 1;i <= n;i ++){
        int mn = 1e9; if(op[i] != o) continue;
        for(int j = 0;j < 3;j ++) if(j != o) mn = min(mn,a[i][op[i]] - a[i][j]);
        dif.push_back(mn);
    }sort(dif.begin(),dif.end());
    for(int i = 0;i < dif.size();i ++) if(cnt[o] > n / 2) ans -= dif[i],cnt[o] --;
    cout << ans << "\n";
}int main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    for(cin >> T;T --;) los();
}
