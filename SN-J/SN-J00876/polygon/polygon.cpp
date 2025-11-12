#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
const int N=6000;
int n;
int a[N];
int sum[N];
int dp[N];
int p[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	sum[1]=a[1];
	sum[0]=0;
	for(int i=2;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	if(n==3){
		if(sum[3]>2*a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	p[1]=1;
	for(int i=2;i<=n;i++){
		p[i]=(p[i-1]*i)%P;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+((p[n]/p[i])/p[n-i])%P)%P;
	}
	cout<<ans;
	return 0;
} 
