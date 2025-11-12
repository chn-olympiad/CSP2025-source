#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
#define x first
#define y second
using namespace std;
const int N=1e4+10,M=1e6+10;
int n,m,k;
ll ans=0;
ll u[M],v[M],w[M],c[15],a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[j];
	}
	
	for(int i=1;i<=m;i++)ans+=w[i];
	cout<<w[i];
	
	return 0;
}
