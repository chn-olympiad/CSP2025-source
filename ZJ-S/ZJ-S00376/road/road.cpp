#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll maxx=5e6,maxn=1e4+5;
ll n,m,k,b[15][maxn],f[maxn],c[15],ans=LLONG_MAX;
bool flag[15];
struct st{
	ll u,v,w;
}a[maxx],d[maxx];

bool cmp(st x,st y){
	return x.w<y.w;
}

ll find(ll x){
	if (x==f[x]) return x;
	return f[x]=find(f[x]);
}

void minree(){
	ll tmp=0,cnt=0,sum=0;
	for (ll i=1;i<=m;i++){
		d[++cnt].u=a[i].u;
		d[cnt].v=a[i].v;
		d[cnt].w=a[i].w;
	}
	for (ll i=1;i<=n;i++) f[i]=i;
	for (ll i=1;i<=k;i++){
		if (flag[i]){
			tmp+=c[i];
			for (ll j=1;j<=n;j++){
				for (ll q=j+1;q<=n;q++){
					d[++cnt].u=j,d[cnt].v=q,d[cnt].w=b[i][j]+b[i][q];
					//cout<<d[cnt].u<<" "<<d[cnt].v<<" "<<d[cnt].w<<"\n";
				}
			}	
		}
	}
	//for (ll i=1;i<=cnt;i++) cout<<d[i].u<<" "<<d[i].v<<" "<<d[i].w<<"\n";
	sort(d+1,d+cnt+1,cmp);
	for (ll i=1;i<=cnt;i++){
		ll fu=find(d[i].u),fv=find(d[i].v);
		if (fu!=fv){
			f[fu]=fv;
			tmp+=d[i].w;
			sum++;
		}
		if (sum==n-1) break;
	}
	ans=min(ans,tmp);
}

void dfs(ll x){
	if (x>k){
		minree();
		return;
	}
	dfs(x+1);
	flag[x]=1;
	dfs(x+1);
	flag[x]=0;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (ll i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
	for (ll i=1;i<=k;i++){
		cin>>c[i];
		for (ll j=1;j<=n;j++) cin>>b[i][j];
	}
	dfs(1);
	cout<<ans;
	return 0;
}



