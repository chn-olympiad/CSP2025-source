#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ans=0;
void dfs(int x,int y,int maxx,int he){
	if(y>=3&&maxx*2<he){
		ans++;
		ans%=998244353;
	}
	int maxxx=max(a[x+1],maxx);
	int hhe=he+a[x+1];
	dfs(x+1,y,maxx,he);
	dfs(x+1,y+1,maxxx,hhe);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int maxx=-1e9,anss=0;
		for(int i=1;i<=n;i++){
			anss+=a[i];
			maxx=max(ans,a[i]);
		}
		if(maxx*2<anss) cout<<1;
		else cout<<0;
		return 0;
	}
	dfs(1,0,-1e9,0);
	cout<<ans;
	return 0;
}
