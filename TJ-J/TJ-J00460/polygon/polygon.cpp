#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[33];
int H;
int ubunto(int u[])
{
	int T=0;
	for(int j=0;j<32;j++)
	{
		if(u[j]==1)
		{
			T++;
		}
	}
	return T;
}

int main()
{
	  freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    const int m=n;
    long long F=0,Z=0;;
    int h[m];
    for(int i=0;i<m;i++)
    {
    	cin>>h[i];
	}
		for(int j=0;j<n;j++)
	{
		for(int k=j+1;k<n;k++)
		{
			
			if(h[j]>h[k])
			{
			int T;
			T=h[k];
			h[k]=h[j];
			h[j]=T;
		}
		}
	}
	bool g=true;
	while(1)
	{
	
		for(int v=0;;v++)
	{
	if(a[v]==0)
	{
		a[v]++;
		break;
	}
	else
	{
	a[v]=0;
	if(v==n-1)
	{
	cout<<Z;
	return 0;}		
	}
		
	}
		
		
		
	for(int l=32;l>-1;l--)
	{
		if(a[l]==1&&g)
		{H=h[l];g=!g;}
		if(a[l]==1)
		{
		F=F+h[l];	
		}
	}
	
	if(ubunto(a)<3||H*2>=F)	
	{	
	}
	else
	{	
		if(Z>=998244353)
		Z=0;
		else
		Z++;
	}
	F=0;g=!g;
	}
}

