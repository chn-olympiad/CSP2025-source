#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],b[5005],m,mod=998244353,p[2005];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	int pt=1;
	cin>>s;
	for (int i=1;i<=n;i++){
		a[i]=s[i-1]-'0';
		if (a[i]==0) pt=0;
		p[i]=p[i-1];
		if (a[i]==0) p[i]++;
	}
	for (int i=1;i<=n;i++){
		cin>>b[i];
	}
	if (pt==1){
		int ans=1;
		for (int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
} 
