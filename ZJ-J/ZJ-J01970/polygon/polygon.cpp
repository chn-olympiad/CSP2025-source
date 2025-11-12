#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
void dfs(int u,int z,int h){
	if(u>n)return;
	dfs(u+1,z,h);
	z=max(z,a[u]);
	h+=a[u];
	if(h>2*z)ans++;
	dfs(u+1,z,h);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

