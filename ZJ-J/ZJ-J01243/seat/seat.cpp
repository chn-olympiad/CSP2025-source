#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=15;
struct node
{
	bool f=0;
	ll x;
}a[N];
ll n,m;
bool cmp(node a,node b)
{
	return a.x>b.x;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;ll hang,lie,t;
	for(ll i=1;i<=n*m;i++) cin>>a[i].x;
	a[1].f=1;sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++) 
		if(a[i].f) 
		{
			t=i;
			break;
		}
	if(t%n) hang=t%n,lie=t/n+1;
	else hang=n,lie=t/n;
	if(lie%2==0) cout<<lie<<" "<<n-hang+1;
	else cout<<lie<<" "<<hang;
	return 0;
}