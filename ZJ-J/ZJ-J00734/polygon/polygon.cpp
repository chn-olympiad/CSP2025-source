#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
int n;
int a[N],mx;
long long ans;
int le;
long long dp[N];
int find(int l,int r,int j,int k){
	int mid,pos;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[mid]+a[j]>k){
			r=mid-1;
			pos=mid;
		}
		else
			l=mid+1;
	}
	return pos;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],mx=max(mx,a[i]);
	if(mx==1){
		for(int i=3;i<=n;i++){
			long long tot=1;
			for(int j=i+1;j<=n;j++)	tot=tot*a[j]%mod;
			ans=(ans+tot)%mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3])	cout<<1;
		else	cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		le=1;
		for(int j=2;j<i;j++){
			le=find(le,j-1,j,a[i]);
			dp[i]=(dp[i]+(j-le)*(j-le-1)/2%mod)%mod;
		}
		long long tot,tri=dp[i];
		for(int j=1;j<le;j++){
			tot=1;
			for(int t=j+1;t<le;t++)	tot=tot*t%mod;
			dp[i]=(dp[i]+tot)*tri%mod;
		}
		ans=(ans+dp[i])%mod;
	}
	cout<<ans;
	return 0;
}
