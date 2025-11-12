#include<bits/stdc++.h>
#define ll long long
#define inf64 (ll)0x3f3f3f3f3f3f3f3f
#define inf32 (int)0x3f3f3f3f
#define _inf32 (int)0xc0c0c0c0
#define _inf64 (ll)0xc0c0c0c0c0c0c0c0
#define N 10010
#define M 1000010
#define K 15
inline int in(){
	int sum=0,op=0,c=getchar();
	while(c<48||57<c)op=(c=='-'?0:1),c=getchar();
	while(48<=c&&c<=57)sum=(sum<<3)+(sum<<1)+c-48,c=getchar();
	return op?(~sum)+1:sum;
}
using namespace std;
struct edge{
	int u,v,w,id;
}e[M<<1];
int n,m,k,nump,nume;
ll ans=inf64,sum;
int c[K],a[K][N];
int fa[N<<1],siz[N<<1];
inline bool cmpw(edge &e1,edge &e2){
	return e1.w<e2.w;
}
inline bool cmpid(edge &e1,edge &e2){
	return e1.id<e2.id;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool mer(int x,int y){
	int X=find(x),Y=find(y);
	if(X==Y)return 0;
	if(siz[X]<siz[Y])swap(X,Y);
	fa[Y]=X;
	siz[X]+=siz[Y];
	siz[Y]=0;
	return 1;
}
int main(){
//	freopen("road3.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=in(),m=in(),k=in();
	for(int i=1;i<=m;i++){
		e[i].u=in(),e[i].v=in(),e[i].w=in();
		e[i].id=i;
	}
	nump=n;
	nume=m;
	for(int i=1;i<=nump;i++){
		fa[i]=i,siz[i]=1;
	}
	sort(e+1,e+1+nume,cmpw);
	for(int i=1;i<=nume;i++){
		if(mer(e[i].u,e[i].v)){
			nump--;
			e[n-nump]=e[i];
			if(nump==1){
				m=n-1;
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		e[i].id=i;
	}
	for(int i=1;i<=k;i++){
		c[i]=in();
		for(int j=1;j<=n;j++){
			a[i][j]=in();
		}
	}
	for(int s=(1<<k)-1;s>=0;s--){
//		cerr<<s<<endl;
		nump=n;
		nume=m;
		sum=0;
		for(int i=0;i<k;i++){
			if((s>>i)&1){
				sum+=c[i+1];
				nump++;
				for(int j=1;j<=n;j++){
					nume++;
					e[nume]={nump,j,a[i+1][j],nume};
				}
			}
		}
		for(int i=1;i<=nump;i++){
			fa[i]=i,siz[i]=1;
		}
		sort(e+1,e+1+nume,cmpw);
		for(int i=1;i<=nume && nump>1;i++){
			if(mer(e[i].u,e[i].v)){
				sum+=e[i].w;
				nump--;
			}
		}
		ans=min(ans,sum);
		sort(e+1,e+1+nume,cmpid);
	}
	printf("%lld",ans);
//	freopen("chk.out","w",stdout);
//	system("fc club.out club5.ans");
}