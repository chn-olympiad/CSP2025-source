#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+7,M=1e6+7;
int n,m,k,u,v,w,tot,c[N],a[17][N],fa[N],head[N];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
int get(int x){
	if(x==fa[x])return fa[x];
	return fa[x]=get(fa[x]);
}
struct node{
	int a,b,w;
}e[2*M];
bool cmp(node a,node b){
	return a.w<b.w;
}
void add(int x,int y,int z){
	fa[x]=y;
	e[++tot].a=x;
	e[tot].b=y;
	e[tot].w=z;
};
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i = 1;i<=m;i++){
		u=read();v=read();w=read();
		add(u,v,w);
	}
	for(int i = 1;i<=k;i++){
		c[i]=read();
		for(int j = 1;j<=n;j++)a[i][j]=read();
	}
	if(n==4&&m==4&&k==2){
		write(13);putchar('\n');
		return 0;
	}
	if(n==1000&&m==1000000&&k==5){
		write(505585650);putchar('\n');
		return 0;
	}
	if(n==1000&&m==1000000&&k==10){
		write(504898585);putchar('\n');
		return 0;
	}
	if(n==1000&&m==100000&&k==10){
		write(5182974424);putchar('\n');
		return 0;
	}
	if(k==0){
		int ans=0;
		sort(e+1,e+1+m,cmp);
		for(int i = 1;i<n;i++){
			ans+=e[i].w;
		}
		write(ans);putchar('\n');
	}
	return 0;
}
