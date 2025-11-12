#include<bits/stdc++.h>
#define int long long
namespace FastIO
{
	inline int read()
	{
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-') f^=1;
			c=getchar();
		} 
		while(c>='0'&&c<='9'){
			x=(x<<3)+(x<<1)+(c^48);
			c=getchar();
		}
		return f?x:~x+1; 
	}
	inline void write(int x)
	{
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar(x%10^48);
	}
	inline void spaceput(int x)
	{
		write(x);putchar(' ');
	}
	inline void output(int x)
	{
		write(x);putchar('\n');
	}
} 
using namespace std;
using namespace FastIO;
constexpr int N=1e4+1e2+5;
constexpr int T=1e3+5;
constexpr int M=1e6+5;
constexpr int inf=1e14;
int n,m,k,len,ans=inf;
int f[N],c[15][N],cg[15],cst[T][T];
vector<int> vec[N];
struct Road
{
	int u,v,w;
	inline friend bool operator < (Road A,Road B){
		return A.w<B.w;
	}
}r[M*20],ppp[M*20];
namespace UnionJoinSet
{
	inline int find(int x)
	{
		return x==f[x]?x:f[x]=find(f[x]);
	}
	inline void merge(int x,int y)
	{
		int fx=find(x),fy=find(y);
		f[fx]=fy;
	}
}
using namespace UnionJoinSet;
void krus()
{
	sort(r+1,r+m+1);int rs=0;
	for(int i=1;i<=m;i++){
		if(find(r[i].u)!=find(r[i].v)){
			merge(r[i].u,r[i].v);rs+=r[i].w;
		}
	}
	write(rs);
}
void dfs(int u)
{
//	if(sum>k) return;
	if(u>k){
		int res=0;len=m;
		for(int j=1;j<=m;j++) ppp[j]=r[j];
		for(int j=1;j<=k;j++){
			if(cg[j]){
				res+=c[j][0];
				for(int i=1;i<=n;i++){
					len++;
					ppp[len].u=n+j,ppp[len].v=i,ppp[len].w=c[j][i];
				}	
			}
		}
//		cout<<res<<'\n';
		sort(ppp+1,ppp+len+1);
//		for(int i=1;i<=n+k;i++) cout<<f[i]<<'\n';
//		cout<<len<<'\n';
		for(int i=1;i<=n+k;i++) f[i]=i;
		for(int i=1;i<=len;i++){
			if(find(ppp[i].u)!=find(ppp[i].v)){
				merge(ppp[i].u,ppp[i].v);res+=ppp[i].w;
//				int x=min(r[i].u,r[i].v),y=max(r[i].u,r[i].v);
//				vec[x].emplace_back(y);cst[x][y]=cst[y][x]=r[i].w;
			}
		}		
//		cout<<res<<'\n';
//		for(int i=1;i<=len;i++){
//			cout<<r[i].w<<' ';
//		}		
//		cout<<'\n'<<'\n';
		ans=min(ans,res);len=m;
		return;
	} 
	cg[u]=1;dfs(u+1);
	cg[u]=0;dfs(u+1);
} 
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();len=m;
	for(int i=1;i<=m;i++){
		r[i].u=read(),r[i].v=read(),r[i].w=read();
	}
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=k;i++){
		c[i][0]=read();
		for(int j=1;j<=n;j++) c[i][j]=read();
	}
	if(!k) krus();
	else{
//		sort(r+1,r+m+1);
//		for(int j=1;j<=k;j++){
//			
//		}
//		for(int i=1;i<=len;i++){
//			if(find(r[i].u)!=find(r[i].v)){
//				merge(r[i].u,r[i].v);ttt+=r[i].w;
//				int x=min(r[i].u,r[i].v),y=max(r[i].u,r[i].v);
//				vec[x].emplace_back(y);cst[x][y]=cst[y][x]=r[i].w;
//			}
//		}		
//		for(int i=1;i<=n;i++) sort(vec[i].begin(),vec[i].end());
		dfs(1);
		write(ans);
	}
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
ans:
13
*/
