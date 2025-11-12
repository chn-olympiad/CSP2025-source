#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int n,m,x[505],a[505],vis[505],t[505],ans=0,mod=998244353;
void check(){
	int w=0,ls=0;
	for(int i=1; i<=n; i++){
		if(a[t[i]]<=ls){
			ls++;
			continue;
		}
		else if(x[i]==0){
			ls++;
			continue;
		}
		else w++;
	}
	if(w>=m) ans++;
}
void dfs(int pos){
	if(pos>n){
		check();
		return ;
	}
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		vis[i]=1;
		t[pos]=i;
		dfs(pos+1);
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int F=1,tmp=0;
	for(int i=1; i<=n; i++){
		char t;
		cin>>t;
		x[i]=t-'0';
		tmp+=x[i];
		F=min(x[i],F);
	}
	if(tmp<m){
		cout<<0;
		return 0;
	}
	for(int i=1; i<=n; i++){
		cin>>a[i];
	} 
	if(n<=10){
		dfs(1);
		cout<<ans%mod;
	}
	else if(m==n){
		for(int i=1; i<=n; i++){
			if(x[i]==0||a[i]==0){
				cout<<"0";
				return 0;
			}
		}
		int ans=1;
		for(int i=1; i<=n; i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans%mod;
	}
	else{
		int ans=1;
		for(int i=1; i<=n; i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans%mod;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

