#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],k,l,b[20][20],r;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
			{
				r++;
				b[j][i]=a[r];
				if(b[j][i]==l)
				{
					cout<<i<<' '<<j;
					return 0;
				}	
			}
		}		
		else if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				r++;
				b[j][i]=a[r];
				if(b[j][i]==l)
				{
					cout<<i<<' '<<j;
					return 0;
				}	
			}
		}
	}
	return 0;
}
