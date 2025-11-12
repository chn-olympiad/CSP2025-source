#include<bits/stdc++.h>
#define mod 998244353
#define N 1000
using namespace std;
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1') flag=0;
	}
	if(flag){
		long long ans=1;
		for(int i=1;i<=n;i++) ans=1ll*i*ans%mod;
		cout<<ans<<endl;
	}
	else{
		cout<<"0"<<endl;
	}
	return 0;
}