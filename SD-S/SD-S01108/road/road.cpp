#include<bits/stdc++.h>
#define N 1000500
#define ed puts("")
#define int long long 
//#define mod 1000000007
#define p_ putchar(' ')
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar(45);
		x=~x+1;
	}
	static int sta[40];
	int top=0;
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while(top) putchar(sta[--top]+48);
	return;
}
struct Edge{
	int u,v,w,id;
}edge[N<<2];
int n,m,k,u,v,w,c,x,fa[N],siz[N];
int num;
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
void add(int u,int v,int w,int id){
	edge[++num].u=u,edge[num].v=v,edge[num].w=w;
	edge[num].id=id;
	return;
}
int find(int x){
	return (fa[x]==x)?x:(fa[x]=find(fa[x]));
} 
int kru(){
	int ans=0,cnt=0;
	sort(edge+1,edge+1+num,cmp);
//	for(int i=1;i<=num;++i){
//		write(edge[i].u),p_,write(edge[i].v),p_,write(edge[i].w),ed;
//	}
	for(int i=1;i<=num;++i){
		int fu=find(edge[i].u),fv=find(edge[i].v);
		if(fu==fv) continue;
		if(siz[u]>siz[v]){
			fa[fu]=fv;
			siz[u]+=siz[v];
		}
		else{
			fa[fv]=fu;
			siz[v]+=siz[u];
		} 
		ans+=edge[i].w;
		if(edge[i].id==1)++cnt;
		if(cnt==n-1) break;
	}
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n+k;++i) fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;++i){
		u=read(),v=read(),w=read();
		add(u,v,w,1);
//		add(v,u,w); 
	}
	for(int i=1;i<=k;++i){
		c=read();
		for(int j=1;j<=n;++j){
			x=read();
			add(i+n,j,x,2);
//			add(j,i,x);
		}
	}
	write(kru());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
5 6 1
1 2 1
1 4 2
1 3 3
3 4 6
2 5 4 
3 5 5
0 10 10 0 0 10 10
*/
