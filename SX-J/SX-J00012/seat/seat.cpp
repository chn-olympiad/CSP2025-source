#include<bits/stdc++.h>
using namespace std;
int n,m,me,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
	int b[n*m]={};
	int a[n+1][m+1]={};
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	me=b[1];
    for(int i=1;i<=n*m;i++)
    {
		for(int j=2;j<=n*m;j++)
		{
			if(b[j]>b[j-1])
			{
				cnt=b[j-1];
				b[j-1]=b[j];
				b[j]=cnt;
			}
		}
	}
    int q=0,v=0;
	for(int i=1;i<=m;i++)
	{
		v++;
		if(v%2!=0)
		{
			for(int j=1;j<=n;j++)
			{
				q++;
				a[j][i]=b[q];
				if(a[j][i]==me)
				{
					cout<<i<<" "<<j;
				}
			}
		}
		else if(v%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				q++;
				a[j][i]=b[q];
				if(a[j][i]==me)
				{
					cout<<i<<" "<<j;
				}
			}
		}
	}
}