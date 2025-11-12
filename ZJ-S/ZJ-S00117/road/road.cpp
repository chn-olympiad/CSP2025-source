#include<bits/stdc++.h>
namespace chuazen{
	#define int long long
	#define max(x,y) (x>y?x:y)
	#define min(x,y) (x<y?x:y)
	#define ufor(i,x,y) for(int i=x;i<=y;i++)
	#define dfor(i,x,y) for(int i=x;i>=y;i--)
	#define N 10005
	#define M 1000005
	#define K 15
	char out[100];
	inline int read(){
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
		while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
		return x*f;
	}
	inline void write(int x){
		if(x<0)putchar('-'),x=-x;
		int tp=0;
		do{out[++tp]=x%10+'0';x/=10;}while(x);
		while(tp)putchar(out[tp--]);
	}
}
using namespace std;
using namespace chuazen;
int n,m,new_m,temp_m[K],k,ans;
int c[K],val[K][N];
struct node{int x,y,v;inline friend bool operator <(node a,node b){return a.v<b.v;}}e[M],new_e[M],temp[K][N];
inline void input(){
	n=read(),m=read(),k=read();
	ufor(i,1,m)e[i].x=read(),e[i].y=read(),e[i].v=read();
	ufor(i,1,k){
		c[i]=read();
		ufor(j,1,n)val[i][j]=read();
	}
}
int fa[N+K];
inline int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
inline int kruskal(int siz){
	ufor(i,1,new_m)new_e[i]={0,0,0}; new_m=0;
	ufor(i,1,siz)fa[i]=i; sort(e+1,e+m+1);
	int res=0,tempx,tempy;
	ufor(i,1,m){
		tempx=find(e[i].x),tempy=find(e[i].y);
		if(tempx==tempy)continue;
		res+=e[i].v;
		fa[tempx]=tempy;
		new_e[++new_m]=e[i];
	}
	ufor(i,1,new_m)e[i]=new_e[i];m=new_m;
	return res;
}
inline void dfs(int dep,int chs,int al_val){
	
	if(dep==k+1)return;
	dfs(dep+1,chs,al_val);
	if(al_val+c[dep]>ans)return;
	ufor(i,1,m)temp[dep][i]=e[i];temp_m[dep]=m;
	ufor(i,1,n)e[++m]={i,n+chs+1,val[dep][i]};
	ans=min(ans,al_val+c[dep]+kruskal(n+chs+1));
	dfs(dep+1,chs+1,al_val+c[dep]);
	ufor(i,1,temp_m[dep])e[i]=temp[dep][i];m=temp_m[dep];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	input();
	ans=kruskal(n);
	if(k==0){write(ans);return 0;}
	dfs(1,0,0);
	write(ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}