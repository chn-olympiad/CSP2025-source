#include <bits/stdc++.h>
#define pii pair<signed,signed>
#define fir first
#define sec second
#define INF 1e18
#define int long long
using namespace std;
const int MAXN=1e4+20;
const int MAXM=2e6+10;
const int mod=13331;
int n,m,k;
int cot=0;
int c[20];
bool if_open[20];
bool vis[MAXN];
//int stk[MAXM];
//int siz=0;
vector<pii >e[MAXN];
int read(){
	int f=1,num=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<1)+(num<<3)+c-'0';c=getchar();}
	return f*num;
}
void write(int x){
	if(x<0){putchar('-');x=(x^(~0))+1;}
	if(x>9)write(x/10);putchar(x%10+'0');
}

int mintree(){
	memset(vis,0,sizeof(vis));
	int an=0;
	priority_queue<pii,vector<pii >,greater<pii > >q;
	for(auto i:e[1]){
		if(!vis[i.fir]&&(i.fir<=n||if_open[i.fir])){
			q.push({i.sec,i.fir});
		}
	}
	vis[1]=1;
	while(!q.empty()){
		int dis=q.top().fir;
		int x=q.top().sec;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		an+=dis;
		for(auto i:e[x]){
			if(!vis[i.fir]&&(i.fir<=n||if_open[i.fir])){
				q.push({i.sec,i.fir});
			}
		}
	}
	return an;
}

int solve(int km){
	if(km>k){
		return mintree()+cot;
	}
	int ans=INF;
	if_open[km+n]=1;
	cot+=c[km];
	ans=min(ans,solve(km+1));
	if_open[km+n]=0;
	cot-=c[km];
	ans=min(ans,solve(km+1));
	return ans;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		int u=read();
		int v=read();
		int w=read();
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int w=read();
			e[i+n].push_back({j,w});
			e[j].push_back({i+n,w});
		}
	}
	write(solve(1));
	return 0;
}
