#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,i,a[1000010],ans,j,sum,f[3][1000010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		for(j=a[i]+1;j<=sum;j++)
			ans+=f[2][j],
			ans%=mod;
		for(j=sum;j>=0;j--)
			f[2][j+a[i]]+=(f[2][j]+f[1][j]),
			f[2][j+a[i]]%=mod;
		f[1][a[i]]++;
		f[1][a[i]]%=mod;
		sum+=a[i];
	}
	cout<<ans;
}
