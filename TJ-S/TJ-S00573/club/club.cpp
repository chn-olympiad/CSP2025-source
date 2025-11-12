#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,c,ans=0,a[50][50],b,d=0,e[1000];
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int q=0;q<n;q++)
			{
				if(a[i][0]<a[q][0])
				{
					c=a[q][0];
					a[q][0]=a[i][0];
					a[i][0]=c;
				}
			}
		}
		b=n/2;
		for(int i=0;i<b;i++)
		{
			ans+=a[i][0];
		}
		e[d-1]=ans;
		d++;
	}
	for(int i=0;i<T;i++)
	{
		cout<<e[i]<<endl;
	}
	return 0; 
}
