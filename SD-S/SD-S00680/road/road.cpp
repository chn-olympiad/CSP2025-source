#include<bits/stdc++.h>
#define ll long long
#define lll __int128
#define pii pair<long long,int>
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define gc getchar() 
using namespace std;
inline int read(){
	int x=0,p=1;
	char ch=gc;
	while(ch<'0'||ch>'9'){
		if(ch=='-') p=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=gc;
	}
	return x*p;
}
const int N=2e4+145,M=2.1e7+145;
const long long inf=2e18;

bool flag=1;
int n,m,k,x,y,z,tot;
int h[N],c[N],a[13][N];
ll rans=inf,dis[N];
bool vis[N];

struct edd{
	int to,nxt,val;
} e[M<<1];
void add(int u,int v,int w){
	e[++tot].nxt=h[u];
	e[tot].to=v;
	e[tot].val=w;
	h[u]=tot; 
}

ll gtans(int x){
	ll tans=0;
	bool can[15]={0};
	for(int i=0;i<k;i++) 
	    if(x>>i&1) can[i+1]=1,tans+=c[i+1];
	
	for(int i=1;i<=n+k;i++) dis[i]=inf,vis[i]=0;
	priority_queue<pii,vector<pii>,greater<pii> > P;
	dis[1]=0;
    P.push(mp(0,1));
    while(!P.empty()){
    	int nd=P.top().se;
    	P.pop();
	    
	    if(vis[nd]) continue;
	    vis[nd]=1;
	    tans+=dis[nd];
	    
	    for(int i=h[nd];i;i=e[i].nxt){
        	int v=e[i].to;
			if(v>n&&can[v-n]!=1) continue;
			
		    if(dis[v]>e[i].val){
		    	dis[v]=e[i].val;
		    	P.push(mp(dis[v],v));
			}
		}
	}
	return tans;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();
    m=read();
    k=read();
    for(int i=1;i<=m;i++){
    	x=read(),y=read(),z=read();
    	add(x,y,z);
    	add(y,x,z);
	}
    for(int i=1;i<=k;i++){
    	c[i]=read();
    	if(c[i]!=0) flag=0;
    	
    	bool fgg=0;
    	for(int j=1;j<=n;j++) {
		    a[i][j]=read(); 
		    if(a[i][j]==0) fgg=1;
		    add(n+i,j,a[i][j]);
		    add(j,n+i,a[i][j]);
		}
		if(fgg==0) flag=0;
	}
	
	if(flag) rans=gtans((1<<k)-1);
	else for(int i=0;i<(1<<k);i++) rans=min(rans,gtans(i));
	printf("%lld",rans);
	return 0;
}

