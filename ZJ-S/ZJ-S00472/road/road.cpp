#include<bits/stdc++.h>
using namespace std;

#define gc getchar()
#define int long long
inline void read(int &x){
	x=0;
	int p=1;
	char ch=gc;
	while(!isdigit(ch)){
		if(ch=='-')p=-1;
		ch=gc;
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	x*=p;
}
#undef gc

const int N=1e6+20;
int n,m,k;

struct node{
	int u,v,w;
}e[N*10];
int fa[N],cnt=0,c[N];
int ct[12][N];
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}

bool cmp(node a,node b){
	return a.w<b.w;
}

void solveA(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			e[++cnt]={n+i,j,ct[i][j]};
		}
	}
	sort(e+1,e+1+cnt,cmp);
	int cc=0;
	int ans=0;
	for(int i=1;i<=cnt;i++){
//		if(cc>n-1+k)break;
		int u=find(e[i].u),v=find(e[i].v),w=e[i].w;
		if(u==v)continue;
		cc++;
		ans+=w;
//		cout<<"now:"<<ans<<endl;
		fa[u]=v;
	}
	cout<<ans;
}

void solveinit(){
	sort(e+1,e+1+m,cmp);
	int ans=0;
	for(int i=1;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v),w=e[i].w;
		if(u==v)continue;
		else{
			fa[u]=v;
			ans+=w;
		}
	}
	cout<<ans<<endl;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/

signed main(){
//	freopen("road3.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		read(u);
		read(v);
		read(w);
		e[++cnt]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			read(ct[i][j]);
		}
	}
	if(k==0){
		solveinit();
		exit(0);
	}
	int spa=0;
	for(int i=1;i<=k;i++){
		if(c[i]==0)spa++;
	}
	if(spa==k){
		solveA();
		exit(0);
	}
}
