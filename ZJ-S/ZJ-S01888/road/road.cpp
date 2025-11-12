#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int MAXN=1e4+10;
const int MAXM=1e6+10;
const int MAXK=20;

int c[MAXK];
int a[MAXK][MAXN];
int flag[MAXK];
int n,m,k;
ll ans;

struct edge{
	int u,v;
	ll w;
};
edge road[MAXM];

struct node{
	int next,to;
	ll w;
};
node e[MAXM*2];
int head[MAXN];
int cnt;

void add(int u,int v,ll w){
	cnt++;
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}

struct bridge{
	int u,v,c;
	ll w;
};

int f[MAXN];
int find(int x){
	if(f[x]==x)return f[x];
	return f[x]=find(f[x]);
}

bool cmp(int x,int y){
	return e[x].w<e[y].w;
}

ll limit;
void dfs(int u){
	for(int i=head[u];i;i=e[i].next){
		int v=e[i].to;
		if(e[i].w>limit)continue;
//		cout<<u<<"to"<<v<<endl;
		int f1=find(u);
		int f2=find(v);
		if(f1!=f2){
			f[max(f1,f2)]=min(f1,f2);
			ans+=e[i].w;
//			cout<<"add:"<<u<<" "<<v<<endl;
		}
	}
}

set<int>S;
vector<edge>Newroad;
int Newa[MAXK][MAXN];

void init(){
	for(int i=1;i<=n;i++)f[i]=i;
	memset(e,0,sizeof(e));
	memset(head,0,sizeof(head));
	cnt=0;
	for(int i=1;i<=m;i++){
		if(road[i].u==road[i].v)continue;
		add(road[i].u,road[i].v,road[i].w);
		add(road[i].v,road[i].u,road[i].w);
	}
	S.clear();
}

int main(){
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	//input
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		road[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		flag[i]=1;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	
	while(true){
		
		init();
		
//		cout<<"Newround\n";
//		for(int i=1;i<=m;i++)cout<<road[i].u<<" "<<road[i].v<<" "<<road[i].w<<endl;
		
		bridge te;
		te.w=INT_MAX;
		for(int i=1;i<=k;i++){
			int min1=INT_MAX;
			int min2=INT_MAX;
			int u=0,v=0;
			for(int j=1;j<=n;j++){
				if(a[i][j]<=min1){
					min1=a[i][j];
					u=j;
				}
			}
			for(int j=1;j<=n;j++){
				if(a[i][j]<=min2&&j!=u){
					min2=a[i][j];
					v=j;
				}
			}
			if(min1+min2+c[i]*flag[i]<te.w){
				te={u,v,i,min1+min2+c[i]*flag[i]};
//				cout<<k<<" "<<u<<" "<<v<<endl;
			}
		}
		
//		cout<<"bridge:"<<te.u<<" "<<te.v<<" "<<te.c<<" "<<te.w<<endl;
		
		limit=te.w;
//		cout<<"limit:"<<limit<<endl;
		dfs(te.u);
		dfs(te.v);
		
//		for(int i=1;i<=n;i++){
//			cout<<find(i)<<" ";
//		}
//		cout<<endl;
		
		int f1=find(te.u);
		int f2=find(te.v);
		if(f1!=f2){
			f[max(f1,f2)]=min(f1,f2);
			ans+=te.w;
			flag[te.c]=0;
//			cout<<"add bridge"<<endl;
//			for(int i=1;i<=n;i++){
//				cout<<find(i)<<" ";
//			}
//			cout<<endl;
		}
		
		
		for(int i=1;i<=n;i++){
			int f1=find(i);
			if(S.find(f1)==S.end())S.insert(f1);
		}
		
		if(S.size()==1)break;
		
//		for(int i=1;i<=n;i++)cout<<find(i)<<" ";
//		cout<<endl;
		
		Newroad.clear();
		for(int i=1;i<=m;i++){
			int f1=find(road[i].u);
			int f2=find(road[i].v);
			if(f1==f2)continue;
			Newroad.push_back({f1,f2,road[i].w});
		}
		m=Newroad.size();
		memset(road,0,sizeof(road));
		for(int i=1;i<=m;i++)road[i]=Newroad[i-1];
		
		memset(Newa,127,sizeof(Newa));
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				Newa[i][find(j)]=min(Newa[i][find(j)],a[i][j]);
			}
		}
		n=S.size();
		memset(a,0,sizeof(a));
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=Newa[i][j];
//				cout<<a[i][j]<<" ";
			}
//			cout<<endl;
		}
		
	}
	
	cout<<ans<<'\n';
	
	return 0;
}