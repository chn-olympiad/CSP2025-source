#include <bits/stdc++.h>
using namespace std;
int n,h,l,s,a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>s>>l;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	h=s;
	for(int i=100;i>=n;i--)
	{
		if(a[i]>a[i+1])
		{
			h=h+1;
			if(h>s)
			{
				l=l+1;
			}
		}
	}
	cout<<l<<" "<<h;
	return 0;
}
