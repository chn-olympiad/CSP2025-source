#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int x,y,w;
int c[10005];
long long sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>w;
		sum+=w;
		c[i]=w;
	}
	sort(c+1,c+n+1);
	cout<<sum-c[n];
	return 0;
}
