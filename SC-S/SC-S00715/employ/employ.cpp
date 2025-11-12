#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s[505],c[505],mx=-1,mn=2,sum,cc;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=x-'0';
		mx=max(mx,s[i]);
		mn=min(mn,s[i]);
		cc+=s[i];
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
		if (c[i]==0){
			cc++;
		}
	}
	if (mx=0 && cc>m){
		cout<<0;
		return 0;
	}	
	sum=1;
	for (int i=1;i<=n;i++){
		sum*=i;
		sum%=998244353; 
	}
	cout<<sum;
} 