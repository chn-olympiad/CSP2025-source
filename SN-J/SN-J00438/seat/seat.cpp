#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[100],c=0,r=0,x[100],y=0;
	cin>>n>>m;
	c=n;
	for(int j=0;j<n*m;j++)
	{
		cin>>b[j];
	}
	for(int i=0;i<100;i++)
	{
		if(b[i]>=x[y])
		{
			x[y]=b[i];
			if(b[0]==x[y])
			{
				break;
			}
			y++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i==n-1)
		{
			r=r+1;
		}
		
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
