#include<bits/stdc++.h>
using namespace std;
long long n,m,a[510],sum,ans=1,Mod=998244353,p[510],w[510];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(long long i=1;i<=n;i++){
		if(s[i]=='1'){
			sum++;
		}
		cin>>a[i];
	}
	if(m==n){
		if(sum!=n){
			cout<<0;
		}
		else{
			for(long long i=1;i<=n;i++){
				ans*=i;
				ans%=Mod;
			}
			cout<<ans;
		}
	}
	else if(sum==n){
		for(long long i=1;i<=n;i++){
			ans*=i;
			ans%=Mod;
		}
		cout<<ans;
	}
	return 0;
}