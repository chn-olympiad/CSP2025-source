#include<iostream>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N=50005,M=2000005;
int n,m,k,head[N],num_edge,f[N],c[N],a[N];
//struct Edge1{
//	int to;
//	int next;
//}e1[M];
struct Edge{
	int from;
	int to;
	int next;
	int cost;
	bool judge;
}e[M];
int find(int p){
	if(f[p]==p)return p;
	return f[p]=find(f[p]);
}
void merge(int x,int y){
	int u=find(x);
	int v=find(y);
	f[u]=v;
}
void add_edge(int from,int to,int cost,int judge){
	e[++num_edge].to=to;
	e[num_edge].from=from;
	e[num_edge].judge=judge;
	e[num_edge].next=head[from];
	e[num_edge].cost=cost;
	head[from]=num_edge;
}
int mp[M];
bool cmp(Edge x,Edge y){
	return x.cost<y.cost;
}
long long kruskal(){//清空f 是否可以单向 
	m=num_edge;
	memset(mp,0,sizeof(mp));
	long long res=0;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		if(e[i].cost==0x7fffffff)continue;
		int x=e[i].from;
		int y=e[i].to;
		if(find(x)!=find(y)){
			merge(x,y);
			mp[i]=1;
			res+=e[i].cost;
		}
	}
	return res;
}


int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w,0);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
//			add_edge(n+2*i-1,j,a[j],1);
//			add_edge(n+2*i-1,n+2*i,c[i],2);
//			add_edge(n+2*i,j,a[j],3);
		}
	}
	for(int i=1;i<=n+2*k;i++)f[i]=i;
	long long ans=kruskal();
//	for(int i=1;i<=k;i++){
//		int res=0;
//		bool flag1=0,flag2=0;
//		for(int j=head[n+2*i-1];j;j=e[j].next){
//			if(e[j].judge==1&&mp[j]&&!flag1){
//				res++;
//				flag1=1;
//			}
//			else if(e[j].judge==2&&mp[j]&&!flag2){
//				res++;
//				flag2=1;
//			}
//		}
//		for(int j=head[n+2*i];j;j=e[j].next){
//			if(e[j].judge==3&&mp[j]){
//				res++;
//				break;
//			}
//		}
//		if(res<3){
//			cout<<i<<' ';
//			for(int j=head[n+2*i-1];j;j=e[j].next){
//				if(mp[j])ans-=e[j].cost;
//			}	
//			for(int j=head[n+2*i];j;j=e[j].next){
//				if(mp[j])ans-=e[j].cost;
//			}
//		}
//	}
//	for(int i=1;i<=n+2*k;i++)f[i]=i;
//	cout<<kruskal();
//	cout<<endl;
	cout<<ans;
//	for(int i=1;i<=m;i++){
//		if(mp[i]){
//			cout<<e[i].from<<' '<<e[i].to<<" "<<e[i].cost<<endl;
//		}
//	}
	
	return 0;
}











