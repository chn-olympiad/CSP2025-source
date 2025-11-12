#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5005],tree[5005],ans;
int qpow(int a,int p){
	int r=1;
	for(;p;p>>=1,a=a*a%mod)p&1&&(r=r*a%mod);
	return r;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	tree[0]=1;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=0;j<=a[i];j++)sum=(sum+tree[j])%mod;
		ans=(ans+qpow(2,i-1)+mod-sum)%mod;
		for(int j=5000;j>=a[i];j--)tree[j]+=tree[j-a[i]];
	}
	cout<<ans;
	return 0;
}
