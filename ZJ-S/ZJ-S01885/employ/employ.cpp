#include<bits/stdc++.h>
using namespace std;
long long n,m,a[502],ans,i,f,mod=998244353;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0||s[i]!='1') f=1;
	}
	if(f) cout<<"0"<<endl;
	else{
		for(i=1,ans=1;i<=n;i++) ans=ans*i%mod;
		cout<<ans<<endl;
	}
	return 0;
}