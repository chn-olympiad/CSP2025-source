#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z,l,h,c,p;
	cin>>n>>m;
	int d=n*m-1;
	int a[d];
	for(int i=1; i<=d; i++)
	{
		cin>>a[i];
	}
	z=a[0];
	for(int o=1; o<=d; o++)
	{
		for(int j=0; j<=o; j++)
		{
			if(j!=1)
			{
				if(a[o-1]>a[j])
				{
					c=a[o-1];
					a[o-1]=a[j];
					a[j]=c;
				}
			}
		}
	}
	for(int k=1; k<=d; k++)
	{
		if(z=a[k-1])
		{
			p=k;
		}
	}
	l=p/n;
	h=p-l*4;
	l=l+1;
	if(l%2==0)
	{
		h=n-h;
	}
	cout<<l-1<<" "<<h-1;
	return 0;
}
