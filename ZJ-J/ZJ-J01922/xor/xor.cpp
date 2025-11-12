#include<bits/stdc++.h>
using namespace std;
int n,k,sum[500005],f[500005],lst[1048580];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;memset(lst,-1,sizeof lst);
    lst[0]=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        sum[i]=sum[i-1]^x;
    }
    for(int i=1;i<=n;i++){
        int c=k^sum[i];
        f[i]=f[i-1];
        if(lst[c]!=-1)f[i]=max(f[i],f[lst[c]]+1);
        lst[sum[i]]=i;
    }
    cout<<f[n];
    return 0;
}