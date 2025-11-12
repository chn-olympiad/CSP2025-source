#include<bits/stdc++.h>
using namespace std;
char s[600];
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ok=true;
	cin>>s+1;
	for(int i=1;i<=n;i++){
		if(s[i]!='1')ok=false;
	}
	if(ok){
		int ans=1;
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans%mod;
		return 0;
	}
	cout<<0;

	return 0;
}
