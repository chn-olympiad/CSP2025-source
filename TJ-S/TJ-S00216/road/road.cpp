#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

int const N=10100,M=2200010;
int n,m,k,idx,f[N];
int head[N],Next[M],ver[M];
ll c[20],val[M],ch,res=LONG_LONG_MAX,nres;
bool use[20],nouse[20];
bool sp=1; 
int uses;

struct node{
	int a,b;
	ll v;
};

struct cmp{
	bool operator ()(node a,node b){
		return a.v>b.v;
	}
};

priority_queue<node,vector<node>,cmp> q;

void init(int x){
	for (int i=1;i<=x;i++) f[i]=i;
	return;
}

int find(int x){
	if (f[x]==x) return x;
	return f[x]=find(f[x]);
}

void union_set(int x,int y){
	int xr=find(x),yr=find(y);
	if (xr==yr) return;
	f[xr]=yr;
	return;
}

void edge(int a,int b,ll v){
	if (a<b) swap(a,b);
	q.push(node{a,b,v});
	return;
}

ll judge(){
	int cnt=0;
	ll tmp=ch;
	int a,b;ll v;
	node t;
	init(n+uses);
	queue<node> q2;
	while (cnt<n+uses){
		t=q.top();q.pop();
		q2.push(t);
		a=t.a,b=t.b,v=t.v;
		//printf("%d %d\n",a,b);
		if (a>n && !use[a-n]) continue;
		if (find(a)==find(b)) continue;
		union_set(a,b);
		cnt++,tmp+=v;
		//printf("%d %d %d\n",a,b,v);
	}
	while (q2.size()){
		q.push(q2.front());
		q2.pop();
	}
	if (tmp<res){
		res=tmp;
	}
	return tmp;
}

void dfs(int x){
	if (x==k){
		use[x]=1,ch+=c[x],uses++;
		judge();
	}
	else if (nouse[x]){
		dfs(x+1);
	}
	else{
		use[x]=1,ch+=c[x],uses++;
		dfs(x+1);
		use[x]=0,ch-=c[x],uses--;
		dfs(x+1);
	}
	return;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int u,v;ll w;
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		scanf("%d %d %lld",&u,&v,&w);
		edge(u,v,w);
	}
	for (int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if (sp && c[i]) sp=0;
		for (int j=1;j<=n;j++){
			scanf("%lld",&w);
			edge(n+i,j,w);
			if (sp && w) sp=0;
		}
	}
	if (sp){
		memset(use,1,sizeof(use));
		uses=k;
		judge();
		printf("%lld",res);
		return 0;
	}
	judge();
	nres=res;
	for (int i=1;i<=k;i++){
		use[i]=1,ch+=c[i],uses++;
		if (judge()>=nres) nouse[i]=1;
		use[i]=0,ch-=c[i],uses--;
	}
	dfs(1);
	printf("%lld",res);
	
	return 0;
}
