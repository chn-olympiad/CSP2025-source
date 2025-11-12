#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,n2;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	n2=n;
	bool b=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)n2--;
		b=(b&(s[i-1]-'0'));
	}
	if(!b||m>n2+1)cout<<0;
	else{
		int ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%mod;
		}
		cout<<ans;
	}
	return 0;
}

