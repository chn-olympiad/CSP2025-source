#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int rd(){int res=0,f=1;char x=getchar();
	while(x<'0'||'9'<x){if(x=='-')f*=-1;x=getchar();}
	while('0'<=x&&x<='9')res=res*10+x-'0',x=getchar();
return res*f;}
void wt(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)wt(x/10);
	putchar(x%10+'0');
return;}
const int N=1e4+100,M=2.5e6+100,K=20;
int n,m,k,c[N],fa[N];
int ans=1e18,idm=0,ida=0;
struct node{
	int u,v,w,id;
}a[M],e[M];
bool use[N];
inline check(int x){return x<=n||use[x];}
bool cmp(node xx,node yy){return xx.w<yy.w;}
int findd(int x){return x==fa[x]?x:fa[x]=findd(fa[x]);}
void merge(int u,int v){
	int fu=findd(u),fv=findd(v);
	if(fu!=fv)fa[fu]=fv;
return;}
int kru(int sum,int len){int res=sum,cnt=0,cnt_nw=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=idm;i++){
		if(use[e[i].id]||!e[i].id)
			if(findd(e[i].u)!=findd(e[i].v)){
				res+=e[i].w,merge(e[i].u,e[i].v),++cnt;
				if(!e[i].id)cnt_nw++;
			}
		if(cnt==len-1||cnt_nw==n-1)break;
	}return res;
}
void kru1(){int cnt=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=ida;i++){
		if(!a[i].id)
			if(findd(a[i].u)!=findd(a[i].v)){
				merge(a[i].u,a[i].v),++cnt;
				e[++idm]=a[i];
			}
		if(cnt==n-1)break;
	}
return;}
int cnt=0;
void dfs(int stp,int sum,int len){
	if(stp==0){++cnt;ans=min(ans,kru(sum,len));return;}
	use[stp+n]=1,dfs(stp-1,sum+c[stp],len+1),use[stp+n]=0;
	dfs(stp-1,sum,len);
return;}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	for(int i=1,u,v,w;i<=m;i++){
		u=rd(),v=rd(),w=rd();
		a[++ida]=(node){u,v,w,0};
	}
	sort(a+1,a+1+ida,cmp);
	kru1();
	for(int i=1;i<=k;i++){
		c[i]=rd();
		for(int j=1,w;j<=n;j++){w=rd();
			e[++idm]=(node){i+n,j,w,i+n};
		}
	}sort(e+1,e+1+idm,cmp);
	dfs(k,0,n);
	wt(ans);
	return 0;
}
