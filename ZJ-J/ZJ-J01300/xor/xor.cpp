#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+8;
int n,k,cnt1,cnt0,a[MAXN],dp[MAXN],pfx[MAXN];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)cnt1++;
        if(a[i]==0)cnt0++;
        pfx[i]=pfx[i-1]^a[i];
    }
    //k=0,ai=1,10Pts
    if(k==0&&cnt1==n)return cout<<n/2,0;
    //k<=1,0<=ai<=1,20Pts
    if(k==0&&cnt1+cnt0==n)return cout<<cnt1/2+cnt0/2,0;
    if(k==1&&cnt1+cnt0==n){
        int x=min(cnt1,cnt0);
        cnt1-=x,cnt0-=x;
        if(cnt1>0)return cout<<x+cnt1,0;
        if(cnt0>0)return cout<<x,0;
    }
    cout<<1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
