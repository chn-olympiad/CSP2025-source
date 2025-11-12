#include<bits/stdc++.h>
using namespace std;
void dfs(int x,int cnt){
	if(x==n+1&&cnt<n-m){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i])
			continue;
		f[i]=0;
		if(cnt>=a[i])
			dfs(x+1,cnt+1);
		else
			dfs(x+1,cnt);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>st;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans<<endl;
}