#include<bits/stdc++.h>
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
using namespace std;
const int N=1e6+10;
char s[N];
int a[N], m, n;
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>(s+1); n=strlen(s+1);
    rep(i, 1, n) if(isdigit(s[i])) a[++m]+=s[i]-48;
    sort(a+1, a+m+1);
    if(a[m]==0) cout<<0<<'\n';
    else rop(i, m, 1) cout<<a[i]; cout<<'\n';
    return 0;
}