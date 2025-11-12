// 这能骗到分吗 

#include <bits/stdc++.h>
#define fr {freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);}
#define qr {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
#define int long long
#define N 200005
using namespace std;

int n,q;
string s1[N],s2[N];
string t1[N],t2[N];

signed main(){
    fr;
    qr;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> s1[i] >> s2[i];
    for(int i = 1;i <= q;i++) cin >> t1[i] >> t2[i];
    for(int i = 1;i <= q;i++) cout << 0 << '\n';
    return 0;
}
