#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,m,a[105],c,r,R;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==R)
		{
			if(i<=n)
			{
				c=1;
				r=i;
				break;
			}
			for(int j=1;j<m;j++)
			{
				if(i-n*j<n)
				{
					c=j+1;
					if(c%2==1)
					{
						r=i-n*j;
					}
					else
					{
						r=n-(i-n*j)+1;
					}
				}
			}
			break;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
