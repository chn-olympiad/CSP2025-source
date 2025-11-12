#include<bits/stdc++.h>

using namespace std;

const int N=1e6+10;

int n,m,k,fa[10010],c[10010],cnt;
int ddd[10][10010];
 
struct node{
	int l,r,dis;
	int ew;
}d[N+100010];

bool cmp(node aaa,node bbb){
	if(aaa.ew!=bbb.ew) return aaa.ew<bbb.ew;
	return aaa.dis<bbb.dis;
}

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin); freopen("road.out","w",stdout);
	cin>>n>>m>>k; cnt=n;
	for(int i=1;i<=n;i++){ cin>>d[i].l>>d[i].r>>d[i].dis; fa[i]=i; }
	bool flag=0;
	for(int i=1;i<=k;i++){
		cin>>c[i]; if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++) cin>>ddd[i][j];
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				d[++cnt].l=j; d[cnt].r=k;
				d[cnt].ew=i; d[cnt].dis=ddd[i][j]+ddd[i][k];
			}
		}
	}
	long long ans=0;
	if(flag==0||k==0){
		if(flag==0) for(int i=n+1;i<=cnt;i++) d[i].ew=0;
		sort(d+1,d+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			int x=d[i].l,y=d[i].r;
			if(find(x)==find(y)) continue;
			ans+=d[i].dis;
			fa[find(x)]=fa[find(y)];
		}
	}else{
		sort(d+1,d+1+n,cmp);
		for(int i=1;i<=n;i++){
			int x=d[i].l,y=d[i].r;
			if(find(x)==find(y)) continue;
			ans+=d[i].dis;
			fa[find(x)]=fa[find(y)];
		}
	}
	cout<<ans<<"\n";
	return 0;	
}
/*
4 4 1
1 2 3
1 3 4
1 4 6
3 4 2
0 1 1 1 1
*/
