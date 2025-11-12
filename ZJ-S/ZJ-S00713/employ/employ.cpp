#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int b[525];
bool v[525];
long long ans;
void dfs(int st,int x){
	if(x>(n-m)) return;
	if(st>n){
		ans=(ans+1)%998244353;
		return;
	}for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=true;
			if(x>=b[i]) dfs(st+1,x+1);
			else if(s[st]=='0') dfs(st+1,x+1);
			else dfs(st+1,x);
			v[i]=false;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>b[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
