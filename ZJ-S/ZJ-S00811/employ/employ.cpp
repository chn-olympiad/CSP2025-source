#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m;
string s;
int c[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	cin>>s;
	for(int i=0;i<s.size();i++)if(s[i]=='0')flag=0;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(flag){
		long long ans=1;
		for(int i=1;i<=n;i++)ans=(ans*i)%mod;
		cout<<ans<<endl;
		return 0;
	}
	return 0;
} 
