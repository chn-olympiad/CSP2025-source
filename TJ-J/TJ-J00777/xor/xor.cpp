#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],sum[N];
int n,k;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    int cnt=0,l=1,tot=0;
    for (int r=1;r<=n;r++){
        l=tot;
        while (l<=r && (sum[r]^sum[l-1])!=k) l++;
        if (((sum[r]^sum[l-1])==k && (l-1)!=r) || ((l-1)==r && a[r]==k)){
            cnt++,tot=r+1;
        }
        if (l==n+1){
            cout<<cnt;
            return 0;
        }
    }
    cout<<cnt;
    return 0;
}
