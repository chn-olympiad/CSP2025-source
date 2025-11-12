#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5010],f[25001000],sumV,ans,mod=998244353;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=sumV;j>=0;j--) (f[j+a[i]]+=f[j])%=mod,(ans+=f[j]*(j>a[i]))%=mod;
		sumV+=a[i];
	}
	cout<<ans;
	return 0;
}//CAO T4 buhui!!!
