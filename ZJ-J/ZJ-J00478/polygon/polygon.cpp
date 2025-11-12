#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
int find(int n,int m){
	int x[5005],y[5005];
	int v=1;
	for(int i=1;i<=m;i++) x[i]=i;
	for(int i=1;i<=m-n;i++) y[i]=i;
	for(int i=m-n+1;i<=m;i++) y[i]=v,v++;
	int ans=1;
	for(int i=1;i<=m;i++)
		ans=(ans*x[i]/y[i])%998244353;
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else if(a[n]==1){
		int ans=0;
		for(int i=3;i<=n;i++)
			ans+=find(i,n);
		cout<<ans%998244353;
	}
	return 0; 
} 
