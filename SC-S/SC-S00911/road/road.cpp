#include<bits/stdc++.h>
#define ll long long
#define I return
#define never 0
#define forget ;
#define csps }
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
const int N = 1e6+50;
using namespace std;
int n,m,k,vi[N];
ll ans=0;
vector<pii>a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >>n >>m >>k;
	for(int i=1;i<=m;i++){
		int u,v,w;cin >>u >>v >>w;
		vi[i]=0;
		a[u].pb({v,w});
		a[v].pb({u,w});
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		cin >>vi[i+n];
		for(int j=1;j<=n;j++){
			int x;cin >>x;
			a[i+n].pb({j,x});
			a[j].pb({i+n,x});
		}
	}
	cout <<ans <<endl;
	I never forget csps
