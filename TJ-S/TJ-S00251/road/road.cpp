#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>

const int N=2e4+10,M=1e6+10;
int n,m,k;

void read(int &x){scanf("%d",&x);}
void read(LL &x){scanf("%lld",&x);}
template <typename T> void tomax(T &a,const T &b){if(a<b) a=b;}
template <typename T> void tomin(T &a,const T &b){if(b<a) a=b;}

struct E{
	int u,v,w;
	bool operator < (const E &a2) const{return w<a2.w;} 
};
vector <E> e;
int a[20][N];

int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return 0;
	fa[x]=y;
	return 1;
}
LL Kur(vector <E> e,vector <E> &tr)
{
	sort(e.begin(),e.end());
	tr.clear();
	LL res=0;
	for(int i=1;i<=n+100;i++) fa[i]=i;
	for(int i=0;i<e.size();i++)
	{
		E &ei=e[i];
		int u=ei.u,v=ei.v,w=ei.w;
		if(merge(u,v)) res+=w,tr.push_back(ei);
	}
	return res;
}

LL ans;
void dfs(int x,vector <E> e,LL w)
{
	if(x>k) return ;
	// not choose
	dfs(x+1,e,w);
	//choose
	w+=a[x][0];
	for(int i=1;i<=n;i++) e.push_back((E){i,n+x,a[x][i]});
	LL res=Kur(e,e);
	tomin(ans,w+res);
	dfs(x+1,e,w);
}

void SOLVE()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		read(u),read(v),read(w);
		e.push_back((E){u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		{
			read(a[i][j]);
		}
	}
	ans=Kur(e,e);
//	printf("unchoose ans=%lld\n",ans);
	dfs(1,e,0);
	cout<<ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--) SOLVE();
	return 0;
}
