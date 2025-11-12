#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void read(int&x){
	char ch=getchar();x=0;
	while(!isdigit(ch)){ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
}
const int N=1e4+100,M=1e6+10;
struct E{
	int val,x,y;
	bool operator<(E b){
		return val<b.val;
	}
}e[M],d[N],g[N];
int a[12][N],cnt;
int f[N];
int Get(int x){
	return f[x]==x?x:f[x]=Get(f[x]);
}
void add(int u,int v,int w){
	e[++cnt].x=u;
	e[cnt].y=v;
	e[cnt].val=w;
}
int c[12];
int main(){
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;read(n);read(m);read(k);
	for(int i=1;i<=n+k;i++)f[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		read(u);read(v);read(w);
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			read(a[i][j]);
		}
	}
	sort(e+1,e+cnt+1);
	ll sum=0;
	int cn=0;
	for(int i=1;i<=cnt;i++){
		if(Get(e[i].x)!=Get(e[i].y)){
			f[Get(e[i].x)]=Get(e[i].y);
			sum+=e[i].val;
			d[++cn]=e[i];
		}
	}
	for(int i=1;i<=k;i++){
		cnt=cn;
		for(int j=1;j<=cn;j++)e[j]=d[j];
		ll kex=0;
		for(int j=1;j<=n+k;j++)f[j]=j;
		for(int j=1;j<=n;j++){
			add(n+i,j,a[i][j]);
		}
		sort(e+1,e+cnt+1);
		int p=0;
		for(int j=1;j<=cnt;j++){
			if(Get(e[j].x)!=Get(e[j].y)){
				f[Get(e[j].x)]=Get(e[j].y);
				kex+=e[j].val;
				g[++p]=e[j];
			}
		}
		if(kex+c[i]<sum){
			sum=kex+c[i];
			cn=p;
			for(int j=1;j<=cn;j++){
				d[j]=g[j];
			}
		}
	}
	cout<<sum<<"\n";
	return 0;
}

