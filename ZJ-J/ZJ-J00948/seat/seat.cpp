#include<bits/stdc++.h>
#define endl '\n'
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define freio(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout);
using namespace std;
int n,m;
int a[105];
int ar;
int seatr;
int xr,yr;
bool cmp(int x,int y)
{
	if(x>y)
	{
		return true;
	}
	return false;
}
//RP++
//9:15 100
int main()
{
	fastio
	freio("seat")
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ar=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
//		cout<<a[i]<<" ";
		if(a[i]==ar)
		{
			seatr=i;
			break;
		}
	}
//	cout<<seatr;
	xr=seatr/n;
	yr=seatr%n;
//	cout<<xr<<" "<<yr<<endl;
	if(yr==0)
	{
		yr=n;
	}
	else
	{
		xr++;
	}
	if(xr%2==0)
	{
		yr=n-yr+1;
	}
	cout<<xr<<" "<<yr;
	return 0;
}
