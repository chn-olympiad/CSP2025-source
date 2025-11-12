#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1) r=a[i];
	}
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			x=i;
			break;
		}
	}
	int i=1,j=1;
	bool flag=1;
	x-=1;
	while(x--)
	{
		if(flag)
		{
			if(i<n)
				i++;
			else
			{
				flag=0;
				j++;
			}
		}
		else
		{
			if(i>1) i--;
			else
			{
				flag=1;
				j++;
			}
		}
	}
	cout<<j<<" "<<i<<"\n";
	return 0;
}
