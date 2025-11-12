#include<bits/stdc++.h>
using namespace std;
int a[109]={},b[101];//ÅÅÐòÍüÁË 

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
	int n,m,c,he,d,e;
	double f;
	cin>>n>>m;
	he=n*m;
	for(int i=1;i<=he;i++)
	{
		cin>>a[i];
		b[i]=a[i]; 
	}
	d=a[1];
	for(int i=1;i<=he;i++)
	{
		for(int j=1;j<he;j++)
		{
			for(int k=1;k<he;k++)
			{
				if(b[j]<a[k])
				{
					b[i]=a[k];
					c=k;
				}
				/*else if(b[j]> a[k])
				{
					b[i]=a[j];
					c=j;
				}*/
			} 
		}
		a[c]=-1;
	}
	for(int i=1;i<=he;i++)
	{
		if(b[i]==d)
		{
			e=i;
		}
	}
	if(e%n==0)
	{
		f=floor(e/n); 
	}
	else
	{
		f=floor(e/n)+1; 
	}
	if(int(f)%2==1)
	{	
		if(e%n==0)
		{
			cout<<f<<" "<<n; 
		}
		else
		{
			cout<<f<<" "<<e%n; 
		}
		
	}
	else if(int(f)%2==0)
	{
		if(e%n==0)
		{
			cout<<f<<" "<<"1"; 
		}
		else
		{
			cout<<f<<" "<<n-(e%n)+1; 
		}
		
	}
	return 0; 
}
