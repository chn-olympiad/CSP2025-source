#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int mod=998244353;
int n,a[N],sum=0,ans=0;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1,cmp);	
	if(n==3){
		if(a[2]+a[3]>a[1]) cout<<1<<'\n';
		else cout<<0<<'\n';
		return 0;
	}
	if(sum==n){
		for(int i=n;i>=3;i--){
			int k=n-i;
			if(k>n/2) k=n-k;
			int p=1,q=1;
			for(int j=n;j>=n-k+1;j--) p*=j;
			for(int j=1;j<=k;j++) q*=j;
			int s=p/q;
			ans=(ans+s)%mod;
		}
	}
	cout<<ans%mod<<'\n';
	return 0;
}
/*
5
1 2 3 4 5
*/