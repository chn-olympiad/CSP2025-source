//T2
//15:06 Wrong idea
//15:27 code
//15:43 restart
//15:52 idea
//16:07 80pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+15,M=1e6+15,K=12;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n,m,k;
struct bian{
	int x,y,z;
	bool operator <(const bian &B)const{return z<B.z;}
}b[M];
int c[K],v[K][N];
int fa[N];
int Getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=Getfa(fa[x]);
}
int total;
struct edge{
	int u,v;
	int c;
	bool operator <(const edge &B)const{return c<B.c;}
}E[N],e[N*K];
int tot;
void add_edge(int x,int y,int z){E[++tot]=(edge){x,y,z};}
int ans;
int d[K];
int pt[K];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();ans=(int)1<<60;
	for(int i=1;i<=m;i++)b[i].x=read(),b[i].y=read(),b[i].z=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)v[i][j]=read();
	}
	sort(b+1,b+1+m);
	for(int i=1;i<=n;i++)fa[i]=i;
	total=0;
	for(int i=1;i<=m && total<n-1;i++){
		int fx=Getfa(b[i].x),fy=Getfa(b[i].y);
		if(fx==fy)continue;fa[fx]=fy;
		total++;
		add_edge(b[i].x,b[i].y,b[i].z);
	}//MST
	for(int s=0;s<(1<<k);s++){
		if((double)clock()/CLOCKS_PER_SEC >= 0.95)break;
		int tmp=0;d[0]=1;int geshu=n-1;
		for(int i=1;i<=k;i++)d[i]=(s>>i-1)&1;
		for(int i=1;i<=k;i++)if(d[i]==1)tmp+=c[i],geshu++;
		for(int i=1;i<=k;i++)pt[i]=1;tot=0;
		for(int i=1;i< n;i++)e[++tot]=E[i];
		for(int i=1;i<=k;i++){
			if(d[i]==0)continue;
			for(int j=1;j<=n;j++)e[++tot]=(edge){i+n,j,v[i][j]};
		}
		sort(e+1,e+1+tot);
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=tot && geshu!=0;i++){
			int fx=Getfa(e[i].u),fy=Getfa(e[i].v);
			if(fx==fy)continue;fa[fx]=fy;
			geshu--;tmp+=e[i].c;
		}
		ans=min(ans,tmp);
	}
	write(ans);putchar('\n');
	return 0;
}