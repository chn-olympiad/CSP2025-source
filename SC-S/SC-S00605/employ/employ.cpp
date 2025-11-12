#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],su=0,o=0,ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		if(c[i]) su++;
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0') o++;
	}
	if(m==n){
		if(su!=n){
			cout<<0;
			return 0;
		}
		if(o){
			cout<<0;
			return 0;
		}
		ans=su;
		for(int i=1;i<n;i++) ans=ans*i%998244353;
		cout<<ans;
		return 0;
	}
	return 0;
}