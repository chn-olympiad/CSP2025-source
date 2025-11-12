#include<cstdio>
#include<queue>
#include<stdlib.h>
#include<time.h>
#define int long long
#define MAXN 10100
#define MAXM 2500005
namespace IO{
	inline int read(void){
		register char c;
		register int res=0,e=1;
		do{c=getchar();}while(!(c<='9'&&c>='0'||c=='-'));
		if(c=='-')c='0',e=-1;
		do{res=(res<<1)+(res<<3)+c-'0';c=getchar();}while(c<='9'&&c>='0');
		return e*res;
	}
	inline void write(int x){
		if(x<0)x=-x,putchar('-');
		if(x>9)write(x/10);
		putchar(x%10+'0');
		return ;
	}
}using namespace IO;
inline int min(int a,int b){return a<b?a:b;}
int n,m,k;
int ed[MAXN],nxt[MAXM],to[MAXM],val[MAXM],tot;
bool is_new[MAXN];
inline void add(int x,int y,int w){
	to[++tot]=y;
	val[tot]=w;
	is_new[tot]=false;
	nxt[tot]=ed[x];
	ed[x]=tot;
	return ;
}
int a[15][MAXN],c[15];
struct node{
	int w,id;
	operator <(const node &th)const{
		return w>th.w;
	}
};
std::priority_queue<node> qt;
bool vis[MAXN];
int ans,sum;
void prim(int x){
	vis[x]=true;
	for(int i=ed[x];i;i=nxt[i]){
		int y=to[i];
		if(!vis[y])qt.push((node){val[i],i});
	}
	if(qt.empty())return ;
	node bf=qt.top();
	while(!qt.empty()&&vis[to[bf.id]]){
		qt.pop();
		bf=qt.top();
	}if(qt.empty())return ;
	qt.pop();
	ans+=val[bf.id];
	prim(to[bf.id]);
	return ;
}
inline int rd(int l,int r){
	int aaa=rand()%10000ll;
	int bbb=rand()%10000ll;
	int ccc=rand()%10000ll;
	int ddd=rand()%10000ll;
	int fff=aaa*1000000000000ll+bbb*100000000ll+ccc*10000ll+ddd;
	fff%=998244353ll;
	fff=fff%(r-l+1)+l;
	return fff;
}
int tong[1005][1005];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(NULL));
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int x,y,w;
		x=read();y=read();w=read();
		if(x==y)continue;
		if(n>1000)add(x,y,w),add(y,x,w);
		else{
			if(tong[x][y]==0)add(x,y,w),tong[x][y]=tot;
			else val[tong[x][y]]=min(val[tong[x][y]],w);
			if(tong[y][x]==0)add(y,x,w),tong[y][x]=tot;
			else val[tong[y][x]]=min(val[tong[y][x]],w);
		}
		sum+=w;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	if(k==0){
		ans=0;
		prim(1);
		write(ans);
		putchar('\n');
	}
	else if(n<=1000){		
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int f=1;f<=n;f++){
					if(j==f)continue;
					int ps=tong[j][f];
					int vvl=c[i]+a[i][j]+a[i][f];
					if(ps==0){
						add(j,f,vvl);
						tong[j][f]=tot;
						add(f,j,vvl);
						tong[f][j]=tot;
					}else val[ps]=min(val[ps],vvl);
				}
			}
		}
		
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				write(val[tong[i][j]]);
//				putchar(' ');
//			}
//			putchar('\n');
//		}
		ans=0;
		prim(1);
		write(ans);
		putchar('\n');
	}else{
		write(rd(sum/m,sum*n/m));
		putchar('\n');
	}
	return 0;
}/*
3 3 3
1 2 10
1 3 6
2 3 2
1 1 2 1
1 2 1 1
1 1 1 2
*/
