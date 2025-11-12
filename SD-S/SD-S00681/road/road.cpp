#include<bits/stdc++.h>
#define ll long long
#define low(X) (X&(-X))
#define pb(A) push_back(A)
#define mk(A,B) make_pair(A,B)
using namespace std;
ll read(){
	ll S=0,F=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')F*=-1;
		ch=getchar();
	}while(isdigit(ch)){
		S=(S<<3)+(S<<1)+(ch^48);
		ch=getchar();
	}return S*F;
}const int N=1e4,M=1e6;
namespace dsu{
	int fa[N+20];
	void init(){
		memset(fa,0,sizeof(fa));
	}int find(int id){
		if(!fa[id])return id;
		return fa[id]=find(fa[id]);
	}
}
int n,m,k,c[11],a[11][N+10];
struct ED{
	int u,v,w,col;
}rd[M+10],ed[N*11+10];
int col[N*11+10];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		rd[i].u=read();rd[i].v=read();rd[i].w=read();
	}sort(rd+1,rd+m+1,[](ED A,ED B){return A.w<B.w;});
	int cnt=0;
	for(int i=1;i<=m;i++){
		int x=dsu::find(rd[i].u),y=dsu::find(rd[i].v);
		if(x==y)continue;
		dsu::fa[y]=x;
		ed[++cnt]=rd[i];
		ed[cnt].col=0;
	}for(int i=1;i<=k;i++){c[i]=read();
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			cnt++;ed[cnt].u=n+i;
			ed[cnt].v=j;ed[cnt].w=a[i][j];
			ed[cnt].col=i;
		}
	}m=cnt;
	sort(ed+1,ed+m+1,[](ED A,ED B){return A.w<B.w;});
	ll ans=(1ll<<60);
	for(int s=0;s<(1<<k);s++){
		dsu::init();ll cnt=0;
		for(int i=0;i<k;i++)if((s>>i)&1)cnt+=c[i+1];
//		printf("S%d\n",s);
		for(int i=1;i<=m;i++){
			if(ed[i].col&&!((s>>ed[i].col-1)&1))continue;
			int x=dsu::find(ed[i].u),y=dsu::find(ed[i].v);
			if(x==y)continue;
			dsu::fa[y]=x;
			cnt+=ed[i].w;
//			printf("%d %d %d\n",ed[i].u,ed[i].v,ed[i].w);
		}ans=min(ans,cnt);
	}printf("%lld\n",ans);return 0;
}

