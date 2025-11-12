#include <bits/stdc++.h>
using namespace std;
const int N = 5E5 + 5;
int n,T,m,ans,a[N],p[N]; string s;
int main(){
    freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m >> s,s = " " + s;
    for(int i = 1;i <= n;i ++) cin >> a[i];
    iota(p+1,p+n+1,1);
    do{
        int cnt = 0;
        for(int i = 1;i <= n;i ++)
            cnt += (s[i] == '1') && (i - 1 - cnt < a[p[i]]);
        ans += cnt >= m;
    }while(next_permutation(p+1,p+n+1));
    cout << ans << "\n";
}
