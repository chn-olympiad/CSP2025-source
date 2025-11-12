#include<bits/stdc++.h>
using namespace std;
using ld=long double;
#define ll long long
#define endl "\n"
#define timn double(clock())/CLOCKS_PER_SEC

const ll N=1e7+5,M=3005,inf=1e18;

int n,m,k,p,f[N],c[N],a[15][N],vis[15];
ld tim;
struct edge{
	int U,V,W;
}E[N],G[N];

int cmp(edge q,edge h){
	return q.W<h.W;
}

int findf(int k){
	if(f[k]==k) return f[k];
	return f[k]=findf(f[k]);
}

ll kru(){
	if(timn-tim>0.9) return (ll)inf;
	sort(G+1,G+p+1,cmp);
	for(int i=1;i<=n;i++) f[i]=i;
	ll ans=0,cnt=0;
	for(int i=1;i<=p;i++){
		if(timn-tim>0.95) return (ll)inf;
		int u=G[i].U,v=G[i].V;
		int fu=findf(u),fv=findf(v);
		if(fu!=fv){
			ans+=G[i].W;
			cnt++; f[fu]=fv;
			if(cnt==n-1){
				return ans;
			}
		}
	}
	return ans;
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	tim=double(clock())/CLOCKS_PER_SEC;
	cin>>n>>m>>k; p=m;
	for(int i=1;i<=m;i++) cin>>E[i].U>>E[i].V>>E[i].W;
	int fl=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) fl=0;
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k==0){
		cout<<kru();
		return 0;
	}
	if(fl){
		for(int i=1;i<=m;i++) G[i]=E[i];
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int l=j+1;l<=n;l++){
					if(l==j) continue;
					G[++p]={j,l,a[i][j]+a[i][l]};
				}
			}
		}
		cout<<kru();
	}
	else{
		for(int i=1;i<=m;i++) G[i]=E[i];
		ll minn=kru();
		for(int msk=1;msk<(1<<k);msk++){
			ll res=0;
			for(int i=0;i<k;i++){
				vis[i+1]=0;
				if((msk>>i)&1) vis[i+1]=1,res+=c[i+1];
			}
			p=m;
			for(int i=1;i<=m;i++) G[i]=E[i];
			for(int i=1;i<=k;i++){
				if(!vis[i]) continue;
				for(int j=1;j<=n;j++){
					for(int l=j+1;l<=n;l++){
						if(timn-tim>0.97){
							cout<<minn<<endl;
							return 0;
						}
						G[++p]={j,l,a[i][j]+a[i][l]};
					}
				}
			}res+=kru();
			minn=min(minn,res);
			if(timn-tim>0.95){
				cout<<minn<<endl;
				return 0;
			}
		}cout<<minn;
	}
	return 0;
}
