#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
using namespace std;
const int N=10020,M=1e6+5;
int n,m,k,x,f[N],a[10];
ll ans;
struct edge{
	int x,y,z;
	inline bool operator<(edge e)const{return z<e.z;}
}e[M],ee[M],tp[M],pe[10][N];
int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
inline ll wrk(int m){
	iota(f+1,f+n+k+1,1);
	ll ans=0;
	for(int i=1;i<=m;i++)if(getf(e[i].x)!=getf(e[i].y))
		ans+=e[i].z,f[f[e[i].x]]=f[e[i].y];
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>ee[i].x>>ee[i].y>>ee[i].z;
	for(int i=0;i<k;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++)cin>>x,pe[i][j]={n+i+1,j,x};
		sort(pe[i]+1,pe[i]+n+1);
	}
	sort(ee+1,ee+m+1);
	iota(f+1,f+n+1,1);
	int ct=0;
	for(int i=1;i<=m;i++)if(getf(ee[i].x)!=getf(ee[i].y)){
		ans+=ee[i].z,f[f[ee[i].x]]=f[ee[i].y];
		ct++,e[ct]=ee[ct]=ee[i];
	}
	for(int i=1;i<(1<<k);i++){
		int ln=n-1;
		ll pre=0;
		for(int j=1;j<n;j++)e[j]=ee[j];
		for(int j=0;j<k;j++)if(i>>j&1){
			for(int l=1;l<=ln;l++)tp[l]=e[l];
			for(int l=1,x=1,y=1;l<=ln+n;l++){
				if(x<=ln&&(y>n||tp[x]<pe[j][y]))e[l]=tp[x++];
				else e[l]=pe[j][y++];
			}
			ln+=n,pre+=a[j];
		}
		//cout<<"$"<<i<<'\n';
		//for(int j=1;j<=ln;j++)cout<<e[j].x<<' '<<e[j].y<<' '<<e[j].z<<'\n';
		ans=min(ans,pre+wrk(ln));
	}
	cout<<ans<<'\n';
	//cerr<<1.*clock()/CLOCKS_PER_SEC<<'\n';
	return 0;
}
//16:35