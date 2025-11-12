#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
不开long long见祖宗 
邻接表战神来也！！！！！！！！ 
rp++;
for(int i=;i<=;i++)
priority_queue<int,vector<int>,greater<int> >q;
upper_bound(d,d+n,x)-d
sort(a+1,a+n+1);
*/
//结构区 
const int INF=0x3f3f3f3f;
struct edge{
	int u,w;
	int to;
};
bool operator >(const edge &x,const edge &y){
	return x.w>y.w;
}
struct node{
	bool kkk,sk;
	int len;
	queue<edge>e;
}d[20005];
//定义区 
int n,m,k,ans,ltd,whh,minn;
priority_queue<edge,vector<edge>,greater<edge> >q;
//函数区 
void add(int u,int v,int w){
	edge xx;
	xx.u=u;
	xx.to=v;
	xx.w=w;
	d[u].e.push(xx);
	d[u].len++;
	return;
}
void bfs(int nd){
	whh=d[nd].len;
	for(int i=1;i<=whh;i++){
		q.push(d[nd].e.front());
		d[nd].e.pop();
	}
	ltd++;
	d[nd].sk=1;
	while(ltd<n){
		if(d[q.top().to].sk==1){
			q.pop();
			continue;
		}
		ans+=q.top().w;
	//	if(d[q.top().to].kkk==1) cout<<"cun "; 
	//	cout<<"k"<<q.top().u<<" "<<q.top().to<<" z"<<q.top().w<<endl;
		ltd+=(d[q.top().to].kkk==0);
		d[q.top().to].sk=1;
		whh=q.top().to;
		q.pop();
		for(int i=1;i<=d[whh].len;i++){
			q.push(d[whh].e.front());
			d[whh].e.pop();
		}
	}
	return;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w,cs,aj;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w); 
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>cs;
		minn=INF;
		for(int j=1;j<=n;j++){
			d[n+2*i-1].kkk=1;
			d[n+2*i].kkk=1;
			scanf("%lld",&aj);
			add(j,n+2*i-1,0);
			minn=min(minn,aj);
		}
		for(int j=1;j<=n;j++){
			add(n+2*i,j,aj);
		}
		add(n+2*i-1,n+2*i,cs+minn);
	}
	bfs(1);
	cout<<ans;
	fclose(0);
	return 0;
}

