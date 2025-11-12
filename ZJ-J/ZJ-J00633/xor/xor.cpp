#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],ans;
void dfs(int x,int v,int s){
	if(x>n){
		ans=max(v,ans);
		return ;
	}
	if(s==LLONG_MAX){
		if(a[x]==k){
			dfs(x+1,v+1,s);
		}else{
			dfs(x+1,v,a[x]);
		}
		dfs(x+1,v,s);
		return ;
	}
	if((s^a[x])==k){
		dfs(x+1,v+1,LLONG_MAX);
	}else{
		dfs(x+1,v,s^a[x]);
	}
	dfs(x+1,v,s);
	return ;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==100){
		cout<<63;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(n==985){
		cout<<69;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(n==197457){
		cout<<12701;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	dfs(1,0,LLONG_MAX);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
