#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,a[5010],mx;
ll res,f[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	mx=a[n];
	f[0]=1,f[a[1]]=1;
	for(int i=2;i<=n;i++){
		for(int j=a[i]+1;j<=mx+1;j++)res=(res+f[j])%mod;
		f[mx+1]=(f[mx+1]*2ll)%mod;
		for(int j=mx-a[i]+1;j<=mx;j++)f[mx+1]=(f[mx+1]+f[j])%mod;
		for(int j=mx;j>=a[i];j--)f[j]=(f[j]+f[j-a[i]])%mod;
	}
	cout<<res;
	return 0;
}
