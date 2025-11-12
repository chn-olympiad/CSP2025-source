#include<iostream>
using namespace std;
int main()
{
    long long n,m,k,u,v,w,c,a;
	int s[10000],min_s=9999,l[10000],minl[10000],min_l=0,x[10000],min_x=0,q;
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
	    cin>>u>>v>>x[i];
	}
	for (int i=1;i<=m;i++)
	{
		if (x[i]<=x[i+1])
		{
			int o=x[i];
			x[i]=x[i+1];
			x[i+1]=o;
		}
	}
	for (int i=1;i<=k;i++)
    {   
	    cin>>s[i];
		for (int p=1;p<=k;p++)
	    {
		    if (min_s>=s[p])
		    {
			    min_s=s[p];
			    q=p;
		    }
	    }
	
		for (int j=1;j<=k;j++)
		{
			if (j==q)
			{
				for (int i=1;i<=k;i++)
				{	
				    cin>>l[j];	
				}
			}
			cin>>a;
		}
	}
	for (int b=1;b<n;b++)
	{
	    if (l[b]<=l[b+1])
	    {
	        int g=l[b];
	        l[b]=l[b+1];
	        l[b+1]=g;
		}
	}
	for (int i=1;i<=3;i++)
	{	
		min_l+=l[i];
	}
	for (int i=1;i<=2;i++)
	{
		min_x+=x[i];
	}
	cout<<min_x+min_s+min_l;
} 