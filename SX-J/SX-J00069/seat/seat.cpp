#include<bits/stdc++.h>
using namespace std;
bool tong[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,rcj,a,c=1,r=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a;
		if(i==1) rcj=a;
		tong[a]=1;
	}
	for(int i=100;i>rcj;i--)
	{
		if(tong[i]==1)
		{
			if(c%2==1) r+=1;
			else r-=1;
			if(r>n||r<1)
			{
				c++;
				if(r>n) r=n;
				else r=1;
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}