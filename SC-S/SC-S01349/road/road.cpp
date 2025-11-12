#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+7;
int u[N];
int v[N];
int w[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)	cin>>u[i]>>v[i]>>w[i];
	int sum=0;
	sort(w+1,w+m+1);
	for(int i=1;i<=n-1;i++)	sum+=w[i];
	cout<<sum;
	return 0;
}