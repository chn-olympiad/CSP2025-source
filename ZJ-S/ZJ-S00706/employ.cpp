#include<bits/stdc++.h>
using namespace std;
int a[100010];
int c[100010];
char s[10010];
int last[10010];
int vis[10010];
int p[10010];
int n,m;
int ll=0;
long long mod=998244353;
void dfs(int k){
	if(k==n){
		int ans=0;
		int q=0;
		for(int i=1;i<=n;i++){
			if(last[i]+q<=c[p[i]]){
				ans++;
			}else if(s[i]=='0'){
				q++;
			}
		}
		if(ans>=m){
			ll++;
			ll%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		last[i]=last[i-1];
		if(s[i]=='1'){
			last[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(0);
	cout<<ll;
	return 0;
}
