#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,p=998244353,t,s,cnt;
ll c[510][510],f[510];
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	f[1]=1;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]*i%p;
	}
	for(int i=1;i<=n;i++){
		c[i][i]=c[i][1]=1;
		for(int j=2;j<=m;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%p;
		}
	}
	cout<<c[n][m]*f[m]%p;
	return 0;
}

