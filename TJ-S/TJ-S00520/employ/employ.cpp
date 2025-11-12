#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
string s;
ll n,m,c[510],ans=1,moddd=998244353;
bool sss=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') sss=false;
	} 
	if(sss){
		for(int i=n;i>=1;i--){
			ans*=i;
			ans%=moddd;
		}
	}else if(n==m){
		cout<<0;
	}else if(m==1){
		ll xxoo;
		for(int i=1;i<=n;i++){
			if(c[i]!=0) xxoo++;
		}
		for(int i=n-1;i>=1;i--){
			ans*=i;
			ans%=moddd;
		}
		ans*=xxoo;
		ans%=moddd;
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
