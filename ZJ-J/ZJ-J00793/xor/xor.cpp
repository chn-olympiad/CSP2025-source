#include<bits/stdc++.h>
using namespace std;
int n,k,xo,ans=0,a[500100];
bool flag=1;
void dfs(int x){
	if(x==n+1){
		return;
	}
	if(flag){
		xo=a[x];
		flag=0;
	}else xo=(xo^a[x]);
	if(xo==k){
		flag=1;
		ans++;
	}
	dfs(x+1);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}