#include<bits/stdc++.h>
using namespace std;
long long n,s,ans,ma,sum,a[5010],f[5010];
long long pd(long long x){
	long long s,ma=0;
	if(f[x-1]==0)return 0;
	for(long long i=1;i<=n;i++)
		if(f[i]==1)s+=a[i],ma=max(ma,a[i]);
	if(s>ma*2)return 1;
	else return 0;
}
void xh(long long x){
	if(pd(x))ans=(ans+1)%998244353;
	if(x==n)return ;
	f[x]=1;xh(x+1);
	f[x]=0;xh(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(long long i=1;i<=n;i++)cin>>a[i],ma=max(ma,a[i]);
	if(n==3){
		sum=a[1]+a[2]+a[3];
		if(sum>ma*2)cout<<1;
		else cout<<0;
		return 0;
	}
	if(ma==1){
		for(long long i=1;i<=n/3;i++){
			s=1;
			for(long long j=1;j<=i*3;j++)s=s*(n-j+1)/j%998244353;
			ans=(ans+s)%998244353;
		}
		cout<<ans;
		return 0; 
	}
	sort(a+1,a+1+n);
	xh(1);
	cout<<ans;
	return 0;
}
