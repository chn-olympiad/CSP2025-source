#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=1e4+5;
ll c[N],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		ans+=c[i];
	}
	cout<<ans;
	return 0;
}