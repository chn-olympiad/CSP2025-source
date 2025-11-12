#include <bits/stdc++.h>
using namespace std;
bool a[101];
int b[10][10],s=100;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int k[m*n+5];
	for(int i=0;i<m*n;i++)
	{
		cin>>k[i];
		a[k[i]]=1;
	}
	for(int j=0;j<m;j++)
	{
		if((j+1)%2!=0)
		{
			for(int i=0;i<n;i++)
			{
				while(!a[s])
					s--;
				if(s==k[0])
				{
					cout<<j+1<<" "<<i+1;
					return 0;
				}
				b[i][j]=s;
				s--;
			}
		}
		if((j+1)%2==0)
		{
			for(int i=n-1;i>=0;i--)
			{
				while(!a[s])
					s--;
				if(s==k[0])
				{
					cout<<j+1<<" "<<i+1;
					return 0;
				}
				b[i][j]=s;
				s--;
			}
		}
	}
	return 0;
}