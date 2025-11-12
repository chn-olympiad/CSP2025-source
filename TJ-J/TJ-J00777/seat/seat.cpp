#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=105;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n*m;i++) cin>>a[i];
    int idx=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for (int i=1;i<=n*m;i++){
        if (a[i]==idx) idx=i;
    }
    cout<<ceil(1.0*idx/n)<<" ";
    int x=ceil(1.0*idx/n);
    int xx=idx%n;
    if (idx%n==0) xx=n;
    if (x%2==0) cout<<n-(xx-1);
    else cout<<xx;
    return 0;
}
