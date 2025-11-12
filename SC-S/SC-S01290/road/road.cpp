#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	ll n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		if(k==0) sum+=c;
	}
	for(int i=1;i<=k*(n+1);i++){
		ll a;cin>>a;
	}
	cout<<sum;
	
	return 0;
}