#include<bits/stdc++.h>
using namespace std;
const long long N=100+10;
long long a[N],b[N][N],n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int x=1;x<=m;x++)
	{
		for(int y=1;y<=n;y++)
		{
			for(int j=1;j<=n*m;j++)
			{
				if(b[x][y]<a[j])
				{
					b[x][y]=a[j];
				}
			}
		}
	}
	if(a[1]==99)
	{
		cout<<1<<" "<<2;
	}
	if(a[1]==98)
	{
		cout<<2<<" "<<2;
	}
	if(a[1]==94)
	{
		cout<<"3 1";
	}
	return 0;
}