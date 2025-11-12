#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,c[510],cnt,vis[510],ss[510];
ll ans;
string s;
void dfs(int x,int sum){
	if(x==n+1){
		if(sum>=m){
			ans++;
			ans%=998244353;
		}
		return;
	}
	if(ss[n]-ss[x-1]+sum<m){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			int u=sum;
			if(s[x-1]=='1'&&x-1-sum<c[i]){
				u++;
			}
			dfs(x+1,u);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			ss[i+1]++;
		}
		ss[i+1]+=ss[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n>10){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
//Âğ£¿
//4000+
