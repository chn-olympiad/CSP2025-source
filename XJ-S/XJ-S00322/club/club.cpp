#include<bits/stdc++.h>
using namespace std;

struct club
{
	int a1,b1,c1;
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		club a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i].a1>>a[i].b1>>a[i].c1;
		}
		int rule=n/2;
		int num=0;
		int maxx1=0,maxx2=0,maxx3=0,f1=0,f2=0,f3=0;
		for(int i=0;i<n;i++)
		{
			if(maxx1<a[i].a1&&i!=n-1)
			{
				maxx1=a[i].a1;
			}
			else if(maxx1<a[i].a1&&i==n-1)
			{
				maxx1=a[i].a1;
				f1++;
				a[i].a1=0;
				while(f1<=rule)
				{
					maxx1=0;
					for(int j=0;j<n;j++)
					{
							if(maxx1<a[i].a1)
							{
								maxx1=a[i].a1;
								f1++;
								a[i].a1=0;
							}
					}
			}
			if(maxx2<a[i].b1)
			{
				maxx2=a[i].b1;
			}
			if(maxx3<a[i].c1)
			{
				maxx3=a[i].c1;
			}
		}
		}
		cout<<num<<endl;
	}
	return 0;
}
