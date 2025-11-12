#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1.1e4+25,M=2e6+25;

int fn,n,m,k;
int c[15],ct[15][N];
ll hv_c;
bool ck[15],isA;

ll l_ans=0x3f3f3f3f3f3f3f3f;

int rd(){
	int x=0;
	char cx='a';
	while ('0'>cx || cx>'9') cx=getchar();
	while ('0'<=cx && cx<='9'){
		x=(x<<3)+(x<<1)+cx-'0';
		cx=getchar();
	}
	return x;
}

struct Edge{
	int u,v,w,tk;
	bool operator<(const Edge &ae)const{
		return w<ae.w;
	}
} e[M];

int fa[N];
int f(int x){
	if (fa[x]==x) return fa[x];
	return fa[x]=f(fa[x]);
}

void solve(){
	for (int i=1;i<=n;++i) fa[i]=i;
	for (int i=1;i<=k;++i){
		if (ck[i]) fa[n+i]=n+i;
	}
	int nn=0;
	ll n_ans=0;
	//cout<<n<<'\n';
	for (int i=1;i<=m;++i){
		if (nn==n-1) break;
		Edge ne=e[i];
		int x=ne.u,y=ne.v,z=ne.w,kk=ne.tk;
		if (!ck[kk]) continue;
		int fx=f(x),fy=f(y);
		if (fx!=fy){
			++nn;
			n_ans+=z;
			fa[fx]=fy;
			//cout<<nn<<" "<<x<<" "<<y<<'\n';
		}
	}
	//cout<<n_ans<<" "<<hv_c<<'\n';
	l_ans=min(l_ans,n_ans+hv_c);
}
void mj(int lev){
	if (lev==k+1){
		solve();
		return;
	}
	mj(lev+1);
	++n;
	hv_c+=c[lev];
	ck[lev]=1;
	mj(lev+1);
	--n;
	hv_c-=c[lev];
	ck[lev]=0;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cin>>n>>m>>k;
	n=rd(),m=rd(),k=rd();
	//cout<<n<<" "<<m<<" "<<k<<'\n';
	fn=n;
	ck[0]=1;
	for (int i=1;i<=m;++i){
		int u,v,w;
		//cin>>u>>v>>w;
		u=rd(),v=rd(),w=rd();
		e[i]=(Edge){u,v,w,0};
	}
	int k0num=0;
	for (int i=1;i<=k;++i){
		int num=0;
		//cin>>c[i];
		c[i]=rd();
		if (c[i]==0) ++k0num;
		for (int j=1;j<=n;++j){
			//cin>>ct[i][j];
			ct[i][j]=rd();
			e[++m]=(Edge){n+i,j,ct[i][j],i};
			if (ct[i][j]==0) ++num;
		}
		//cout<<c[i]<<" "<<num<<'\n';
	}
	sort(e+1,e+m+1);
	if (k0num==k) isA=1;
	/*if (k0num==k){
		for (int i=1;i<=k;++i) ck[i]=1;
		solve();
	}*/
	mj(1);
	cout<<l_ans;
	return 0;
} 
