#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
#define ll long long
#define R(x) x=read()
using namespace std;
const int N=1e4+10,M=1e6+10,K=15,W=1<<5;
int n,m,k,c[K],vis[M],cnt,fa[M],len1[W+10],len2[W+10];
ll ans,res;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^'0');
		ch=getchar();
	}return x*f;
}
int find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
struct edge{
	int u,v,w;
}r1[M],r2[K][N],r3[M<<1],org[N],r4[W+10][N*6],r5[W+10][N*6],t[M<<1];
bool cmp(struct edge a,struct edge b){
	return a.w<b.w;
}
int lowbit(int x){
	return x&(-x);
}
inline void getR3(int s){
	int l=1,r=1;
	if((k>5&&s<W)||k<=5){
		while(l<=n&&r<=len1[s]+1){
			if(l==n&&r==len1[s]+1)break;
			if(l==n){
				r3[++cnt]=r4[s][r],++r;continue;
			}else if(r==len1[s]+1){
				r3[++cnt]=org[l],++l;continue;
			}
			if(org[l].w<r4[s][r].w){
				r3[++cnt]=org[l],++l;
			}else r3[++cnt]=r4[s][r],++r;
		}
	}else{
		int ss=(s&(W-1)),res=0;
		while(l<=n&&r<=len1[ss]+1){
			if(l==n&&r==len1[ss]+1)break;
			if(l==n){
				t[++res]=r4[ss][r],++r;continue;
			}else if(r==len1[ss]+1){
				t[++res]=org[l],++l;continue;
			}
			if(org[l].w<r4[ss][r].w){
				t[++res]=org[l],++l;
			}else t[++res]=r4[ss][r],++r;
		}
		s=s>>5;
		l=r=1;
		while(l<=res+1&&r<=len2[s]+1){
			if(l==res+1&&r==len2[s]+1)break;
			if(l==res+1){
				r3[++cnt]=r5[s][r],++r;continue;
			}else if(r==len2[s]+1){
				r3[++cnt]=t[l],++l;continue;
			}
			if(t[l].w<r5[s][r].w){
				r3[++cnt]=t[l],++l;
			}else r3[++cnt]=r5[s][r],++r;
		}
	}
}
void init(){
	if(k>5){
		for(int i=1;i<W;i++){
			for(int p=1;p<=5;p++){
				if((i>>p-1)&1){
					for(int s=1;s<=n;s++){
						r4[i][++len1[i]]=r2[p][s];
					}
				}
			}
			sort(r4[i]+1,r4[i]+1+len1[i],cmp);
		}
		for(int i=1;i<W;i++){
			for(int p=6;p<=k;p++){
				if(((i<<5)>>p-1)&1){
					for(int s=1;s<=n;s++){
						r5[i][++len2[i]]=r2[p][s];
					}
				}
			}
			sort(r5[i]+1,r5[i]+1+len2[i],cmp);
		}
	}else{
		for(int i=1;i<(1<<k);i++){
			for(int p=1;p<=k;p++){
				if((i>>p-1)&1){
					for(int s=1;s<=n;s++){
						r4[i][++len1[i]]=r2[p][s];
					}
				}
			}
			sort(r4[i]+1,r4[i]+1+len1[i],cmp);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	R(n),R(m),R(k);
	for(int i=1;i<=m;i++){
		R(r1[i].u),R(r1[i].v),R(r1[i].w);
	}
	for(int i=1;i<=k;i++){
		R(c[i]);
		for(int p=1;p<=n;p++){
			R(r2[i][p].w);
			r2[i][p].u=n+i,r2[i][p].v=p;
		}
	}
	init();
	int u,v;ans=1e18;
	res=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(r1+1,r1+m+1,cmp);
	for(int i=1;i<=m;i++){
		u=find(r1[i].u),v=find(r1[i].v);
		if(u==v)continue;fa[u]=v;
		org[++cnt]=r1[i],res+=r1[i].w;
	}ans=min(ans,res);
	for(int S=1;S<(1<<k);S++){
		res=0;cnt=0;getR3(S);
		for(int i=1;i<=k;i++){
			if((S>>i-1)&1){
				res+=c[i];
			}
		}
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=cnt;i++){
			u=find(r3[i].u),v=find(r3[i].v);
			if(u==v)continue;
			res+=r3[i].w;fa[u]=v;
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}
