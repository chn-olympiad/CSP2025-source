# include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m;
ll r,a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	if(a[1]!=1) cout<<1<<" "<<1;
	else cout<<-1;
	return 0;
}
