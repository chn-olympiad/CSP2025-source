#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn=1e4+26,mxm=1e6+26,mxs=1026,inf=1e9+26;
namespace Ai_I{
	inline void I(int &x){
		x=0;
		char c=getchar();
		while(c<'0'||c>'9')
			c=getchar();
		while(c>='0'&&c<='9'){
			x=x*10+c-'0';
			c=getchar();
		}
		return ;
	}
}
using namespace Ai_I;
int n,s,m,k,u,v,w,fa[mxn],sz[mxn],top,c[13],cnt[mxs];
struct edge{
	int u,v,w;
	friend bool operator<(edge xy,edge zb){
		return xy.w<zb.w;
	}
}e[mxm],a[13][mxn],d[mxs][mxn];
inline int F(int x){
	return x==fa[x]?x:fa[x]=F(fa[x]);
}
inline bool M(int x,int y){
	if((x=F(x))==(y=F(y)))
		return 0;
	if(sz[x]>sz[y])
		swap(x,y);
	sz[fa[x]=y]+=sz[x];
	return 1;
}
ll ans,res[mxs],ress;
inline void H(edge *b,edge *a,int la,edge *c,int lc){
	top=0;
	for(int i=1,j=1;i<=la||j<=lc;)
		if(i<=la&&(j>lc||a[i]<c[j])){
			b[++top]=a[i];
			i++;
		}
		else{
			b[++top]=c[j];
			j++;
		}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	I(n);I(m);I(k);
	for(int i=1;i<=m;i++){
		I(u);I(v);I(w);
		e[i]={u,v,w};
	}
	for(int i=1;i<=n;i++)
		sz[fa[i]=i]=1;
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
		if(M(e[i].u,e[i].v)){
			ans+=e[i].w;
			d[0][++top]=e[i];
		}
	cnt[0]=top;
	for(int i=1;i<=k;i++){
		I(c[i]);
		for(int j=1;j<=n;j++){
			I(w);
			a[i][j]={n+i,j,w};
		}
		sort(a[i]+1,a[i]+n+1);
	}
	s=1<<k;
	for(int i=1,p,ii;i<s;i++){
		p=(i&-i);
		res[i]=res[ii=(i^p)];
		for(int j=0;j<k;j++)
			if(p>>j&1){
				p=j+1;
				break;
			}
		ress=(res[i]+=c[p]);
		H(d[i],d[ii],cnt[ii],a[p],n);
		for(int j=1;j<=n+k;j++)
			sz[fa[j]=j]=1;
		cnt[i]=top;
		for(int j=1;j<=top;j++)
			if(M(d[i][j].u,d[i][j].v))
				ress+=d[i][j].w;
		ans>ress?ans=ress:0;
	}
	printf("%lld",ans);
	return 0;
}
/*
细节扣太慢了 
1h10min 大样例没过再说吧 
2h27min
*/
