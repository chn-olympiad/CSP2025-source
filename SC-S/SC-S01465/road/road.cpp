#include<vector>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int M=5e6+5,N=10105,inf=1e17;
struct Ed{int f,l,w;}ed[M];
int n,m,k,ans,cost[1200],anu[1200],siz[1200],fas[N][1200],C[15];
vector<Ed> num[1200];
vector<int> id;
bool cmp(Ed a,Ed b){return a.w<b.w;}
int Findfa(int x,int p){
	if(x!=fas[x][p]) fas[x][p]=Findfa(fas[x][p],p);
	return fas[x][p];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;int f,l,w,c;ans=inf;
	for(int i=1;i<=n+k;i++){
		for(int j=0;j<(1<<k);j++)
			fas[i][j]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>f>>l>>w;
		ed[i]={f,l,w};
	}
	for(int i=1;i<=k;i++){
		cin>>C[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			ed[++m]={i+n,j,w};
		}
	}
	sort(ed+1,ed+1+m,cmp);
	for(int i=0;i<(1<<k);i++){
		int tot=0;
		for(int a=1;a<=k;a++){
			if(i>>(a-1)&1) tot++,cost[i]+=C[a];
		}
		siz[i]=n-1+tot;
	}
	int ok=(1<<k),qwq=0,ouo=0;
	for(int i=1;i<=m&&ok;i++){
		qwq++;
		f=ed[i].f,l=ed[i].l,w=ed[i].w;int c=0;
		if(f>n) c=f-n;
		else ouo++;
		for(int a=0;a<(1<<k);a++){
			if(!siz[a]) continue;
			if(c){if(!(a>>(c-1)&1)) continue;}
			int fx=Findfa(f,a),fy=Findfa(l,a);
			if(fx==fy){
				if(a==0) break;
				continue;
			}
			fas[fx][a]=fy;siz[a]--;
			if(!siz[a]) ok--;
			anu[a]+=w;
		}
	}
	for(int i=0;i<(1<<k);i++) ans=min(ans,anu[i]+cost[i]);
	cout<<ans;
	return 0;
}