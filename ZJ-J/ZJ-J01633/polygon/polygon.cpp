#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans,vis[5005];
void dfs(int b,int le,int maxx,int prev){
	if(le>2*maxx&&b>=3){
		ans++;
	}
	for(int i=prev+1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(b+1,le+a[i],max(maxx,a[i]),i);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
