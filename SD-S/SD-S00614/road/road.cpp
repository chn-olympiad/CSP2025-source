#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100005;
ll ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		ans+=c;
	}
	for(int i=1;i<=m+1;i++){
		ll k;
		cin>>k;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
