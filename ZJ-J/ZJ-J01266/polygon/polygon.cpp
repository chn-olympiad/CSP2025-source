#include<bits/stdc++.h>
using namespace std;
#define N 5010
#define mod 998244353
int a[N];
long long dfs(int i,int x,int len,int n){
    if(i==0){
        if(len>a[x]*2) return 1;
        else return 0;
    }long long ans=0;
    for(int j=x+1;j<=n-i+1;j++){
        ans+=dfs(i-1,j,len+a[j],n);
        ans%=mod;
    }
    return ans;
}long long ksm(int a,int b){
	long long t=a,ans=1;
	while(b){
		if(b&1) ans=t*ans%mod;
		t=t*t%mod;
		b>>=1;
	}return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    bool z=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[1]) z=0;
    }if(z){
        long long ans=ksm(2,n)-n-1;
        ans-=1ll*(n-1)*n/2;
        while(ans<0) ans+=mod;
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=3;i<=n;i++){
        ans+=dfs(i,0,0,n);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
