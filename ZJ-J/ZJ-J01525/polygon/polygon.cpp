#include <bits/stdc++.h>
#define N 5007
#define ll long long
#define mod 998244353
using namespace std;
int n,a[N];
ll ans=0;
ll c(int n,int m){
	ll k=1;
	if(m>n/2)return c(n,n-m);
	for(int i=n-m+1;i<=n;++i)k*=i;
	for(int i=2;i<=m;++i)k/=i;
	return k%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		ans=0;
	}
	else if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		int maxn=max(max(a,b),c);
		if(a+b+c>2*maxn){
			ans=1;
		}
	}
	else{
		int maxn=-1;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]>maxn)maxn=a[i];
		}
		if(maxn==1){
			for(int i=3;i<=n;++i){
				ans+=c(n,i);
				ans=ans%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}//#Shang4Shan3Ruo6Shui4
