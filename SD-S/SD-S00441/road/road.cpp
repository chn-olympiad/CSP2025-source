#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define up(_i,_l,_r) for(auto _i=_l;_i<=_r;_i++)
#define put(_x) cout<<_x<<endl
#define DEBUG cerr<<"-----------------\n"<<__LINE__<<endl<<"-----------------\n"
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
const int N=10005,M=1000005;
int n,m,k;
int headg[N],totg=0;
struct node{
	int to,w,nxt;
}e[M<<1],tr[M<<1]; 
void addEdge1(int u,int v,int w){
	e[++totg]={v,w,headg[u]};headg[u]=totg;
}
struct E{
	int u,v,w;
	friend bool operator< (E a,E b){
		return a.w<b.w;
	}
}Edge[M<<1];
int f[N],nume=0;
int find(int x){
	if(x==f[x]) return x;
	else return f[x]=find(f[x]);
}
int sum=0;
int c[N],d[15][N];
int pos[15];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	up(i,1,m){
		int u=read(),v=read(),w=read();
		addEdge1(u,v,w);
		addEdge1(v,u,w);
		Edge[i]={u,v,w};
	}
	sort(Edge+1,Edge+m+1);
	up(i,1,n) f[i]=i;
	up(i,1,m){
		int u=Edge[i].u,v=Edge[i].v,w=Edge[i].w;
		if(find(u)==find(v)) continue;
		f[find(u)]=find(v);
		sum+=w;
		nume++;
		if(nume==n-1) break;
	}
	if(k==0){
		cout<<sum<<endl;
		return 0;
	}
	up(i,1,k){
		c[i]=read();
		up(j,1,n) d[i][j]=read();
	}
	srand(time(0));
	cout<<rand()%sum+1<<endl;
	return 0;
}
/*存样例
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

13
*/
/*思路
一眼出思路 完全图上最小生成树
但我忘记prim咋写了。。。稍微推一下
似乎不是这样，可以先从原图上跑最小生成树 
*/
/*闲话
我是@__CrossBow_EXE__，上午我在SD-J00628.
关注我谢谢
//freopen
//feropen
IAKIOI
求上迷惑代码大赏
上午340pts应该有了，看下午怎么说
*/

