#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,s[510],c[510],cn=0;
int p[510],v[510],ss[510];
int f=1;
string h;
long long ans;
void dfs(int x){
	if(x<=n){
		for(int i=1;i<=n;i++){
			if(v[i]) continue;
			v[i]=1;
			p[x]=i;
			dfs(x+1);
			v[i]=0;
		}
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[p[i]]>ss[i]&&s[i]) cnt++;
		}
		if(cnt>=m) ans++,ans%=mod;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>h;
	for(int i=1;i<=n;i++){
		s[i]=h[i-1]-'0';
		ss[i]=ss[i-1]+!s[i];
		if(s[i]!=1) f=0;
	}
	for(int i=1;i<=n;i++) cin>>c[i],cn+=!c[i];
	if(f){
		n-=cn;ans=1;
		while(n){
			ans*=n--;
			ans%=mod;
		}
		cout<<ans%mod;
		return 0; 
	}
	dfs(1);
	cout<<ans;
	return 0;
}
