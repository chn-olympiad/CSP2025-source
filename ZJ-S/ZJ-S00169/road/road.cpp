#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace IO{
	inline int read(){
		int res=0;
		char c=getchar();
		while(c<'0'||'9'<c)	c=getchar();
		while('0'<=c&&c<='9'){
			res=(res<<3)+(res<<1)+(c&15);
			c=getchar();
		}return res;
	}
	inline void print(ll num){
		if(num>9) print(num/10);
		putchar('0'+num%10);
		return;
	}
	inline void write(ll num){
		print(num);
		putchar('\n');
		return;
	}
}
using namespace IO;
const int kMaxN=2e4+5;
const int kMaxM=1e6+5;
const int kMaxO=11;
int n,m,o,oo,tot;
ll ans=1ll<<62,sm;
struct E{
	int x,y;
	ll w;
	inline bool friend operator<(E a,E b){
		return a.w<b.w;
	}
}e[kMaxM<<1],ee[kMaxM<<1];
struct D{
	ll w,val[kMaxN];
}a[kMaxO];
namespace BCJ{
	int bcj[kMaxN],sz[kMaxN];
	inline int find(int x){
		return x==bcj[x]?x:bcj[x]=find(bcj[x]);
	}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		if(sz[x]>sz[y]) swap(x,y);//sz[x]小 
		bcj[x]=y,sz[y]+=sz[x];
		return;
	}
}
using namespace BCJ;
bool used[kMaxO];
inline ll clc(){
	int i,x,y,cnt=1,tmp,lim=n;
	ll res=sm;
	memset(used,false,sizeof(used));
	sort(e+1,e+m+1);
	for(i=1;i<=tot;++i) bcj[i]=i,sz[i]=1;
	for(i=1;i<=m;++i){
		x=find(e[i].x),y=find(e[i].y);
		if(x==y) continue;
		merge(x,y);
		++cnt;
		tmp=0;
		if(e[i].x>n){
			tmp=e[i].x-n;
			if(!used[tmp]){
				used[tmp]=true;
				++lim;
			}
		}
		res+=e[i].w;
		if(cnt>=lim) break;
	}
	return res;
}
inline void dfs(int dep){
	if(dep>oo){
		int i;
		for(i=1;i<=m;++i) ee[i]=e[i];
		ans=min(ans,clc());
		for(i=1;i<=m;++i) e[i]=ee[i];
		return;
	}
	//不开发该镇 
	dfs(dep+1);
	//开发该镇
	sm+=a[dep].w;
	int mm=m,i;
	for(i=1;i<=n;++i){
		++m;
		e[m]={n+dep,i,a[dep].val[i]};
	}
	dfs(dep+1);
	m=mm;
	sm-=a[dep].w;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j;
	n=read(),m=read(),o=read();
	tot=n+o;
	for(i=1;i<=m;++i){
		e[i].x=read(),e[i].y=read(),e[i].w=read();
	}
	for(i=1;i<=o;++i){
		a[i].w=read();
		for(j=1;j<=n;++j) a[i].val[j]=read();
	}
	for(i=1;i<=o;++i){
		if(a[i].w==0){
			for(j=1;j<=n;++j){
				++m;
				e[m]={n+i,j,a[i].val[j]};
			}
		}
		else{
			++oo;
			a[oo]=a[i];
		}
	}
	dfs(1);
	write(ans);
	return 0;
}
