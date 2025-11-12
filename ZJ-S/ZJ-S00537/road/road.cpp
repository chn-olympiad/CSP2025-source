#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
const int M=1e6+5;
const int K=20;

int n,m,k;

int fa[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int c[K];
int a[K][N];

struct B{
	int x,y,d,vis;
	bool operator<(B x)const{
		if(d==x.d)return c[vis]>c[x.vis];
		return d>x.d;
	};
}b[N];
priority_queue<B>q[2],q1;

set<int>se;

long long ans;

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	
	for(int i=1;i<=m;i++){
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);
		b[i]={x,y,d,0};
	}
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	sort(b+1,b+1+m);
	
	for(int i=1;i<=n;i++)fa[i]=i;
	
	for(int i=1,j=0;i<=m;i++){
		int x=b[i].x;
		int y=b[i].y;
		int d=b[i].d;
		int tx=find(x);
		int ty=find(y);
		if(tx!=ty){
			j++;
			fa[tx]=ty;
			ans+=d;
			q[0].push({x,y,d,0});
		}
		if(j==n-1)break;
	}
	
	if(k==0){
		cout<<ans;
		return 0;
	}
	
	for(int i=1,v=0;i<=k;i++){
		q1=q[v];
		for(int j=1;j<=n;j++){
			q[v].push({n+1,j,a[i][j],i});
		}
		for(int i=1;i<=n*2;i++){
			fa[i]=i;
		}
		long long cnt=0;
		se.clear();
		while(q[v].size()){
			B nw=q[v].top();
			q[v].pop();
			int x=nw.x;
			int y=nw.y;
			int d=nw.d;
//			cout<<x<<" "<<y<<" "<<d<<"\n";
			int vis=nw.vis;
			int tx=find(x);
			int ty=find(y);
			if(tx!=ty){
				fa[tx]=ty;
				cnt+=d;
				se.insert(vis);
				q[v^1].push({x,y,d,vis});
			}
		}
		long long res=0;
		for(auto it:se){
			res+=c[it];
		}
		if(ans>cnt+res){
			ans=cnt+res;
		}else{
			q[v]=q1;
		}
		v^=1;
//		cout<<i<<" : "<<ans<<"\n";
	}
	
	cout<<ans;
	
	return 0;
}