#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],vis[501],cnt,b[501];
string s;
int check(int b[]){
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){
		if(sum>=b[i]) continue;
		if(s[i-1]=='1')ans++;
		else sum++;
	}
	if(ans>=m) return 1;
	return 0;
}
void dfs(int x){
	if(x==n+1){
		if(check(b)==1) cnt++;
		cnt%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[x]=a[i];	
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1); 
	cout<<cnt;
	return 0;
}
