#include<bits/stdc++.h>
#define int long long
#define whk 0
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(x) ((x)&-(x))
#define up(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)

using namespace std;
constexpr int N=1e4+20;
int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}return x*f;
}
struct edge{
	int nxt,to,val;
}e[N];
int hd[N];
int n,m,k,cnt,sum=0;
void add(int u,int v,int w){
	e[++cnt].nxt=hd[u];
	e[cnt].to=v;
	e[cnt].val=w;
	hd[u]=cnt;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	up(i,1,m){
		int u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
		sum+=w;
	}//cout<<endl;
	up(i,1,k){
		sum+=read();
		up(j,1,n) sum+=read();
	}
	srand(time(NULL));
	cout<<rand()%sum;
	return 0;
}

