#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e7;
ll n,m;
struct city{
	ll u,v,w;
}b[N];
ll c[15];
ll a[15][N];
ll k;
ll ans;
bool cmp(city a,city b)
{
	return a.w<b.w;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	sort(b+1,b+1+m,cmp);
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int i=1;i<=n;i++)
		{
			cin>>a[j][i];
		}
	}

	
	for(int i=1;i<=m;i++)
	{
		ans+=b[i].w;
		
	}
	cout<<ans;
	return 0;
}

