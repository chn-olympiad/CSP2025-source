#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second

const int N=10010;
const int M=1200010;

const int K=15;

using namespace std;

int n,m,k,ans;

int fa[N];

int c[K],t[K][N];

//map<pii,int>mp;

struct edge{
	int u,v,w;
	bool operator<(const edge &b)const{return w<b.w;}
}e0[M],e[M];

inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+(ch&15),ch=getchar();
	return ret*f;
}

int getfa(int x){
	return (fa[x]==x)?x:(fa[x]=getfa(fa[x]));
}

int rres;

//void _init(){
//	sort(e+1,e+m+1);
//	int cnt=0;
//	for(int i=1;i<=n;i++)fa[i]=i;
//	for(int i=1;i<=m;i++){
//		int fx=getfa(e[i].u),fy=getfa(e[i].v);
//		if(fx==fy)continue;
//		fa[fx]=fy;
////		e[i].f=1;
//		rres+=e[i].w;
//		cnt++;
//		if(cnt==n-1)break;
//	}
//}

int _m;

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	_m=m;
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
//		mp[mkp(u,v)]=mp[mkp(v,u)]=w;
		e0[i].u=u,e0[i].v=v,e0[i].w=w;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)t[i][j]=read();
	}
//	_init();
	int flg=0,cc=0;
	for(int i=1;i<=k;i++){
//		int mxd=0,id1=0,id2=0,eid=0;
//		for(int j=1;j<=n;j++){
//			if(t[i][j]<minn){
//				minn=t[i][j];
//				id=j;
//			}
//		}
//		int minnn=1e15,minid=0;
//		for(int j=1;j<=n;j++){
//			if(j==id)continue;
//			if(t[i][j]<minnn){
//				minnn=t[i][j];
//				minid=j;
//			}
//		}
//		int f=0;
//		int _w=c[i]+t[i][id]+t[i][minid];
//		int excost=c[i];
//		for(int j=1;j<=_m;j++){
//			if(!e[j].f)continue;
//			int w=t[i][e[j].u]+t[i][e[j].v];
//			if(e[j].w-w>0)excost-=e[j].w-w;
//		}
		int tot=0;
		for(int j=1;j<=_m;j++)e[++tot]=e0[i];
		e[++tot]=(edge){0,i+n,c[i]};
		for(int j=1;j<=n;j++){
			e[++tot]=(edge){i+n,j,t[i][j]};
		}
		sort(e+1,e+tot+1);
		int res=0;
		int cnt=0;
		for(int j=0;j<=n+k;j++)fa[j]=j;
		for(int j=1;j<=tot;j++){
			int fx=getfa(e[j].u),fy=getfa(e[j].v);
			if(fx==fy)continue;
			fa[fx]=fy;
			cnt++;
			res+=e[j].w;
			if(cnt==n+1)break;
		}
		if(res<rres){
			e0[++m]=(edge){0,i+n,c[i]};
			for(int j=1;j<=n;j++){
				e0[++m]=(edge){i+n,j,t[i][j]};
			}
			flg=1;
			cc++;
		}
		
//		for(int j=1;j<=_m;j++){
//			int w=t[i][e[j].u]+t[i][e[j].v];
//			if(e[j].w-w>=mxd){
//				mxd=e[j].w-w;
//				id1=e[j].w;
//				id2=e[j].v;
//			}
//		}
//		if(!eid)continue;
//		e[eid].w=c[i]+t[i][id1]+t[i][id2];
//		for(int j=1;j<=_m;j++){
//			if(e[j].u==id1&&e[j].v==id2)continue;
//			int w=t[i][e[j].u]+t[i][e[j].v];
//			if(w<e[j].w)e[j].w=w;
//		}
//		if(f){
//			e[++m]=(edge){0,i+n,c[i],0};
//		printf("_w=%lld\n",_w);
//			e[++m]=(edge){i,id,c[i]+t[i][id],0};
//			for(int j=1;j<=n;j++){
//				if(j==id)continue;
//				e[++m]=(edge){i+n,j,t[i][j],0};
//			}
//			flg=1;
//			cc++;
//		}
		
	}
//	for(int i=1;i<=m;i++)e[i]=e0[i];
	sort(e0+1,e0+m+1);
	for(int i=0;i<=n+k;i++)fa[i]=i;
	int cnt=0;
//	int d=0;
//	printf("%lld\n",m);
	for(int i=1;i<=m;i++){
		int fx=getfa(e0[i].u),fy=getfa(e0[i].v);
		if(fx==fy)continue;
//		if(e[i].u==0||e[i].v==0)d=1;
//		printf("%lld --- %lld , w = %lld\n",e[i].u,e[i].v,e[i].w);
		fa[fx]=fy;
		ans+=e0[i].w;
		cnt++;
		if(cnt==n+flg+cc-1){
//			printf("111\n");
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
