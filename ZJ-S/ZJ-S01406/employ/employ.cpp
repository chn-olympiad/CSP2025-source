#include<bits/stdc++.h>
using namespace std;
long long c[505],a[505],n,vis[505],ans=0;
void dfs(long long x){
	if(x==n){
		ans++;
		return;
	}
	for(long long i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>c[i];
	}
	for(long long i=1;i<=n;i++){
		a[i]=i;
	}
	dfs(0);
	cout<<ans;
}
