#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

inline int Rd(){
	int x=0,f=1; char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}

struct edge{
	int u,v,w;
	friend bool operator < (edge A,edge B){
		return A.w<B.w;
	}
}e1[1000006],e2[200005],e3[200005],e[11][10004];
int tot2,tot3;

int fa[20004];
int findf(int u){
	if (fa[u]==u) return u;
	return fa[u]=findf(fa[u]); 
}

int c[11];


int n,m,k;
long long res,ans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=Rd(); m=Rd(); k=Rd();
	for (int i=1;i<=m;i++){
		int u=Rd(),v=Rd(),w=Rd(); 
		e1[i]=(edge){u,v,w};
	}
	sort(e1+1,e1+m+1);
	for (int i=1;i<=n+k+1;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int u=e1[i].u,v=e1[i].v, w=e1[i].w;
		int fu=findf(u),fv=findf(v);
		if (fu!=fv){
			fa[fu]=fv;
			e2[++tot2]=(edge){u,v,w};
			ans=ans+w;
		}
	}
//	for (int i=1;i<=tot2;i++){
//		printf("%lld %lld %lld\n",e2[i].u,e2[i].v,e2[i].w);
//	}
	
	for (int j=1;j<=k;j++){
		c[j]=Rd();
		for (int i=1;i<=n;i++){
			int x=Rd();
			e[j][i]=(edge){i,n+j,x};
		}
		sort(e[j]+1,e[j]+n+1);
	}
	
	for (int S=0;S<(1<<k);S++){
		long long cc=0; res=0;
		tot3=0;
		for (int i=1;i<=tot2;i++){
			e3[i]=e2[i];
		}tot3=tot2;
		for (int i=1;i<=k;i++){
			if ((1<<(i-1))&S){
				cc=cc+c[i];
				for (int j=1;j<=n;j++){
					e3[++tot3]=e[i][j];
				}
			}
		}
		sort(e3+1,e3+tot3+1); 
		for (int i=1;i<=n+k+1;i++) fa[i]=i;
		for (int i=1;i<=tot3;i++){
			int u=e3[i].u,v=e3[i].v, w=e3[i].w;
			int fu=findf(u),fv=findf(v);
			if (fu!=fv){
				fa[fu]=fv;
				res=res+w;
			}
		}
		ans=min(ans,res+cc);
	}
	printf("%lld\n",ans);
	return 0;
}
/*

*/
