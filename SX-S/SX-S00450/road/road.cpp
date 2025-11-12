#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,fa[10005],a[15][10005],c[15],ans=1e18;
struct node{
	int x,y,z;
	bool operator<(const node &A)const{
		return z<A.z;
	}
}e[1000005],ne[1000005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].x>>e[i].y>>e[i].z;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<1<<k;i++){
//		cout<<ans<<endl;
		for(int j=1;j<=m;j++) ne[j]=e[j];
		for(int j=1;j<=n;j++) fa[j]=j;
		int sum=0,cnt=m;
		for(int j=1;j<=k;j++){
			if(((i>>(j-1))&1)==0) continue;
			sum+=c[j];
			for(int x=1;x<=n;x++)
				for(int y=1;y<=n;y++){
					if(x==y) continue;
					ne[++cnt]={x,y,a[j][x]+a[j][y]};
				}
		}
//		cout<<sum<<endl;
		sort(ne+1,ne+cnt+1);
		for(int j=1;j<=cnt;j++){
			int p=find(ne[j].x),q=find(ne[j].y);
			if(p==q) continue;
			fa[q]=p,sum+=ne[j].z;
		}
		ans=min(ans,sum);
		if(n*n>100000000) cout<<ans,exit(0);
	}
	cout<<ans;
	return 0;
}      
/*3 2 1
1 2 3
2 3 3
1 1 3 2*/  
