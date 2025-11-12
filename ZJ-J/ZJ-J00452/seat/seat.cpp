#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;
ll n,m;
struct node
{
	ll cj,bh;
	bool operator<(const node &n2)const
	{
		return cj>n2.cj;
	}
}s[200];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>s[i].cj;
		s[i].bh=i;
	}
	sort(s+1,s+1+n*m);
	ll wz=0;
	for(int i=1;i<=n*m;i++)
	{
		if(s[i].bh==1)
		{
			wz=i;
		}
	}
	ll l=(wz+n-1)/n;
	ll h=wz-n*(l-1);
	if(l%2==1)
	{
		cout<<l<<" "<<h;
	}
	else
	{
		cout<<l<<" "<<n-h+1;
	}
	return 0;
}
