#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int i,n,j,a[1000010],f[1000010],yc,s;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	f[0]=1;
	for(i=1;i<n;i++){
		yc=yc*2%mod;
		for(j=5010;j>=0;j--)
			if(j+a[i]>5010)
				yc=(yc+f[j])%mod;
			else
				f[j+a[i]]=(f[j+a[i]]+f[j])%mod;
		if(i>1)
			for(j=a[i+1]+1;j<=5010;j++){
				s=(s+f[j])%mod;
			}
		s=(s+yc)%mod;
	}
	cout<<s;
}
