#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct s{
	ll x;
	ll y;
};
bool cmp(s x,s y)
{
	return x.x>y.x;
}
ll vis[3];
int main()
{
	ll t;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		ll n,sum=0;
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			s a[5];
			for(ll j=1;j<=3;j++)
			{
				cin>>a[j].x;
				a[j].y=j;
			}
			sort(a+1,a+1+3,cmp);
			if((vis[a[1].y]+1)<=(n/2)) sum+=a[1].x,vis[a[1].y]++;
			else 
			{
				sum+=a[2].x;
				vis[a[2].y]++;
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
} 