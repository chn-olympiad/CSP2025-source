#include<bits/stdc++.h>
#define int long long
#define debug printf("!!!\n")
using namespace std;
int read(){
	char c=getchar();
	int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar()){
		if(c=='-') f=-1;
	}
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	return x*f;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void write(int x,char c){
	write(x);putchar(c);
}
const int N=1e4+5,M=2e6+5,K=15,S=1<<10|5;
int n,m,k,ei,fa[M],ans,edi;
struct edge{
	int u,v,w;
}E[M],e[M],ed[M];
struct node{
	int c,a[N];
}b[K];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int kruskal(int tot,bool tp){
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(e+1,e+1+ei,cmp);
	int cnt=0,sum=0;
	for(int i=1;i<=ei;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v)){
			fa[find(u)]=find(v);
			if(!tp) ed[++edi]=(edge){u,v,w};
			cnt++;sum+=w;
			if(cnt==tot-1) break;
		}
	}
	return sum;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int a=read(),b=read(),c=read();
		E[i]=(edge){a,b,c};
	}
	for(int i=1;i<=k;i++){
		b[i].c=read();
		for(int j=1;j<=n;j++) b[i].a[j]=read();
	}
	for(int i=1;i<=m;i++) e[i]=E[i];
	ei=m;
	ans=kruskal(n,0);
	for(int i=1;i<=edi;i++) E[i]=ed[i];
	m=edi;
	int mx=(1<<k);
	for(int sta=1;sta<mx;sta++){
		for(int i=1;i<=m;i++) e[i]=E[i];
		ei=m;
		int cnt=0,s=0;
		for(int i=0;i<k;i++){
			if(sta>>i&1){
				cnt++;
				for(int j=1;j<=n;j++) e[++ei]=(edge){n+i+1,j,b[i+1].a[j]};
				s+=b[i+1].c;
			}
		}
		ans=min(ans,s+kruskal(n+cnt,1));
	}
	write(ans,'\n');
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
