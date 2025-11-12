#include<bits/stdc++.h>
using namespace std;
int main()
{ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[10005],b[1005][1005],n,m,r,c,ma=0,pg=0,nm,cnm,cnmd;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	pg=a[0];
	for(int j=0;j<n*m;j++)
	{
		for(int i=0;i<n*m;i++)
		{
			if(a[i+1]>a[i])
			{
				nm=a[i];
				cnm=a[i+1];
				a[i]=cnm;
				a[i+1]=nm;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[i][j]=a[ma];
				if(b[i][j]==pg)
			{
				r=i;
				c=j;
			}
			ma++;
		}
	}

	for(int i=0;i<9;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<r<<" "<<c;
	return 0;
} 
