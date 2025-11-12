#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
ll n,m,k,a[N][N],b[N],d[N][N],ddd=1e9;
struct node{
	ll x,y;
};
vector<node> v[N];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > > q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		if(i==j) a[i][j]=0,d[i][j]=0;      
		else a[i][j]=1e10;
		b[j]=1e10;d[i][j]=1e10;
	}
	for(int i=1;i<=m;i++){
		ll u,l,w;
		cin>>u>>l>>w;
		a[l][u]=a[u][l]=min(a[l][u],w);
		
	}for(int i=1;i<=k;i++){
		ll c;cin>>c;
		ddd=min(ddd,c);
		for(int j=1;j<=n;j++){
			ll p;
			cin>>p;
			b[j]=min(b[j],p);
			//cout<<b[j]<<endl;
		}
		
	}for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			a[i][j]=min(a[i][j],b[j]+b[i]);	
			d[i][j]=a[i][j];
		}
	}for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				//cout<<d[i][j]<<endl;
			}
		}
	}
	ll ans=1e10;
	for(int i=1;i<=n;i++){
		ll cnt=0;
		for(int j=1;j<=n;j++){
			cnt+=d[i][j];
		}ans=min(ans,cnt);
	
	}cout<<ans+ddd;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
