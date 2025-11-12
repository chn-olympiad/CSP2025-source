#include<bits/stdc++.h>
using namespace std;
int n,a[100005][4],maxx,x,y,z;
int f[100005];
void dfs(int now){
	if(now>n){
		if(x<=n/2&&y<=n/2&&z<=n/2){
			int sum=0;
			for(int i=1;i<=n;i++)
				sum+=a[i][f[i]];
			maxx=max(maxx,sum);
		}
		return;
	}
	f[now]=1;x++;
	dfs(now+1);
	x--;
	f[now]=2;y++;
	dfs(now+1);
	y--;
	f[now]=3;z++;
	dfs(now+1);
	z--;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		maxx=0;
		x=0,y=0,z=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		dfs(1);
		cout<<maxx<<'\n';
	}
	return 0;
}
