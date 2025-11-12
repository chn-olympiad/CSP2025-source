#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[5005][5005];
vector<int> v[10005];
int b[10005];
int c[15][10005];
int ls[10005];
int zt[10005];
int bian[10005];
int ans=0;
void f(int x,int cnt){
	if(cnt==0) return;
	zt[x]=1;
	for(int i=0;i<v[x].size();i++){
		if(zt[i]==0){
			ls[i]=min(ls[i],a[i][x]);
		}
	}
	int minn=1000000,p=0;
	for(int i=1;i<=n;i++){
		if(ls[i]<=minn){
			p=i;
			minn=ls[i];
		}
	}
	ans+=minn;
	f(p,cnt-1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
		v[x].push_back(y);
		v[y].push_back(x);
		bian[i]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	sort(bian+1,bian+1+m);
	for(int i=1;i<=n-1;i++) ans+=bian[i];
	cout<<ans;
//	memset(ls,998244353,sizeof(ls));
//	f(1,n-1);
//	cout<<ans;
}
