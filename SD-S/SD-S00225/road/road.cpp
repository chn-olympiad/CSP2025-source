#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long 
inline int Read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-48;c=getchar();}
	return x*f;
}
inline void Write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>9) Write(x/10);
	putchar(x%10+'0');
}
const int N=1e4+10,M=1e6+10;
int n,m,k,tot=0,ans=0;
int c[20],a[20][N];
bool vis[20];
int fa[N+20];
struct edge{
	int from,id,to,w;
	int nxt;
}in[M<<1];
bool cmp(edge A,edge B){
	return A.w<B.w;
}
int findf(int x){
	if(fa[x]==x) return x;
	return fa[x]=findf(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=Read();m=Read();k=Read();
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=Read();v=Read();w=Read();
		in[++tot]=(edge){u,0,v,w,0};
	}
	for(int i=1;i<=k;i++){
		c[i]=Read();
		for(int j=1;j<=n;j++){
			a[i][j]=Read();
			in[++tot]=(edge){i+n,i,j,a[i][j]+c[i],0};
		}
	}
	sort(in+1,in+tot+1,cmp);
	int nn=n-1,cnt=0;
	for(int i=1;i<=tot;i++){
		if(cnt>=nn) break;
		int fx=0,fy=0;
		fx=findf(in[i].from),fy=findf(in[i].to);
		if(fx==fy) continue;
		if(fx!=fy){
			ans+=in[i].w;
			if(in[i].id){
				if(!vis[in[i].id]){
					vis[in[i].id]=1;
					nn++;
				}
				else ans-=c[in[i].id];
			}
			fa[fx]=fy;
			cnt++;
		}
		if(cnt>=nn) break;
	}
	printf("%lld\n",ans);
	return 0 ;
}
