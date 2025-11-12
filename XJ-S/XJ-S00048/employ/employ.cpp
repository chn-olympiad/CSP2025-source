#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[600];string s;
bool vis[600];
int sum[600],ans=0;
void aaa(int x[600]){
	int fin=0,vip=0;
	for(int i=1;i<=n;i++){
		if(fin>=x[i]){
			fin++;
			continue;
		}
		if(s[i]=='1'){
			vip++;
		}else{
			fin++;
		}
	}
	if(vip>=m){
		ans++;
		ans%=mod;
	}
}
void dfs(int x){
	if(x==n+1){
		aaa(sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==true) continue;
		vis[i]=true;
		sum[x]=a[i];
		dfs(x+1);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans%mod;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
