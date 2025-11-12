#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1005],tot;
bool cmp(int w,int q)
{
	return w>q;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,h=0,l=1;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	tot=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1;i<=n*m;i++)
	{
		if(l%2==0) h--;
		else h++;
		if(h==n+1) h--,l++;
		if(h==0) h++,l++;
		if(a[i]==tot)
		{
			cout<<l<<" "<<h;
			return 0;
		}
	}
	return 0;
}
