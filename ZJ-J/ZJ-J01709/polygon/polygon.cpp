#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n,t,w,ans,sum,a[10001],f[10001],k,d[10001];
void dfs(long long x,long long y,long long z,long long s){
	if(z==w+1){
		if(s<k){
		ans++;
		//cout<<s<<' '<<x<<' '<<y<<endl;
		}
		ans%=mod;
		return;
	}
	for(int i=x;i<=y;i++){
		if(d[i]==0&&s+a[i]<k){
			d[i]=1;
			dfs(i+1,y,z+1,s+a[i]);
			d[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	for(int i=3;i<=n;i++){
		if(a[i]>=f[i-1])continue;
		else{
			ans++;
			k=f[i-1]-a[i];
			for(int j=1;j<=i-3;j++){
				w=j;
				dfs(1,i-1,1,0);
			}
		}
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
