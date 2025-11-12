#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+10;
int n,m,T,tot,sum,c[MAXN],a[20][MAXN];
int f[MAXN];

struct node{
	int u,v,w;
}b[MAXN<<4];

bool cmp(node x,node y){
	return x.w<y.w;
}

void add(int u,int v,int w){
	b[++tot].u=u;
	b[tot].v=v;
	b[tot].w=w;
}

int find(int x){
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}

int kruscal(){
	int cnt=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=tot;i++){
		int u=find(b[i].u);
		int v=find(b[i].v);
	//	cout<<u<<" "<<v<<endl;
		if(u!=v){
			f[u]=v;
			sum+=b[i].w;
			cnt++;
		//	cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<endl;
		}
		if(cnt==n-1)return sum;
	}
	return sum;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//cin>>n>>m>>T;
	scanf("%lld%lld%lld",&n,&m,&T);
	int u,v,w;
	for(int i=1;i<=m;i++){
		//cin>>u>>v>>w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	//cout<<1<<endl;
	for(int i=1;i<=T;i++){
//		cin>>c[i];
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			int ans=0x3ffffffff;
		//	cout<<ans<<endl;
			for(int k=1;k<=T;k++){
				ans=min(a[k][j]+a[k][i]+c[k],ans);
			}
			add(i,j,ans);
			add(j,i,ans);
		}
	}
	sort(b+1,b+tot+1,cmp);
//	for(int i=1;i<=tot;i++)
//	cout<<b[i].u<<" "<<b[i].v<<" "<<b[i].w<<endl;
	cout<<kruscal()<<endl;
	//cout<<-1<<endl;
}
