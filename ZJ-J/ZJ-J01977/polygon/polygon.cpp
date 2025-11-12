#include<bits/stdc++.h>
using namespace std;
const int N=-0x3e3e3e3f;
int n,a[5001],ans,tot=1,x,mx,mxx;
void dfs(int tot,int x){
	if(tot>n){
		if(x>mx*2) ans++;
		return;
	}
	mxx=mx;
	mx=a[tot];
	dfs(tot+1,x+a[tot]);
	mx=mxx;
	dfs(tot+1,x);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<ans;
	return 0;
}
