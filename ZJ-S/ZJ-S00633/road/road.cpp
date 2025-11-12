#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M=2e6+1e1;
const int N=1e4+1e2;
int cnt,n,m,k;
struct Edge
{
 int u,v,w,band;
 inline bool operator <(const Edge &other)const
 {
	if(other.w>w)	return true;
	return false;
 }
}edge[M<<1|1];
int ans[N],father[N];
inline int find(int x)
{
 if(father[x]==x)	return x;
 return father[x]=find(father[x]);
}
inline void Kruscal(int k,int Num)
{
 int res=0,num=0;	k<<=1;
 for(int i=1;i<=n+k;i++)	father[i]=i;
 for(int i=1;i<=m;i++)
 {
 	if(edge[i].band!=0&&(((1<<edge[i].band)&k)==0))	continue;
 	if(find(edge[i].v)==find(edge[i].u))			continue;
 	res+=edge[i].w,father[find(edge[i].v)]=find(edge[i].u),num++;
 	if(num==Num-1)	break;
 }
 ans[k>>1]+=res;
 return ;
}
inline void read(int &x)
{
 char c=getchar();	x=0;
 while(c<'0'||c>'9')	c=getchar();
 while(c>='0'&&c<='9')
 	x=(x<<3)+(x<<1)+c-48,c=getchar();
}
int x[N];
bool flag=true;
signed main()
{
 freopen("road.in","r",stdin);	freopen("road.out","w",stdout);
 read(n),read(m),read(k);
 for(int i=1;i<=m;i++)
 	read(edge[i].u),read(edge[i].v),read(edge[i].w);
 for(int i=1;i<=k;i++)
 {
 	read(x[i]),flag&=(x[i]==0);	bool Exist=false;
 	for(int j=1;j<=n;j++)
 		read(edge[++m].w),edge[m].u=i+n,edge[m].v=j,edge[m].band=i,Exist|=(edge[m].w==0);
 	flag&=Exist;
 }
 int answer=1e18;	sort(edge+1,edge+m+1);
 if(flag)
 {
 	Kruscal((1<<k)-1,n+k),printf("%lld\n",ans[(1<<k)-1]);
 	return 0;
 }
 for(int i=0;i<(1<<k);i++)
 {
 	int Num=n;
 	for(int j=1;j<=k;j++)
 		if(i&(1<<(j-1)))	ans[i]+=x[j],Num++;
 	Kruscal(i,Num),answer=min(answer,ans[i]);
 }
 printf("%lld\n",answer);
 return 0;
}
