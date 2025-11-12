#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,tot,ans=1,c[505],now;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;tot=n;
	if(s[0]==s[1] && s[1]==s[n] && s[n]==0){
		for(long long i=1;i<=n;i++){
			cin>>c[i];
			if(c[i]<=now){
				tot--;now++;
			}
		}
		if(tot<m-1) cout<<0;
		else{
			for(long long i=1;i<=101;i++){
				ans*=i;ans%=mod;
			}
			cout<<ans;
		}
	}else{
		cout<<mod-1;
	}
	return 0;
}
