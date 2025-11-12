#include <bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin >>a[i];
	}
	x=a[1];
	for(int i=1; i<=n*m; i++)
	{
		for(int j=1; j<=n*m; j++)
		{
			if(a[j]<a[j+1])
			{
				int ans=a[j];
				a[j]=a[j+1];
				a[j+1]=ans;
			}
		}
	}
	for(int i=1; i<=n*m; i++)
	{
		if(x==a[i])
		{
			y=i;
		}
    }
    if(y<m || y==m)
	{
		cout <<1<<" "<<y;
	}
	if(y>m && (y<2*m || y==2*m))
	{
		cout <<2<<" "<<2*m+1-y;
	}
	if(y>2*m && (y<3*m || y==3*m)) 
	{
		cout <<3<<" "<<y-2*m; 
	}
	if(y>3*m && (y<4*m || y==4*m)) 
	{
		cout <<4<<" "<<4*m+1-y; 
	}
	if(y>4*m && (y<5*m || y==5*m)) 
	{
		cout <<5<<" "<<y-4*m; 
	}
	if(y>5*m && (y<6*m || y==6*m)) 
	{
		cout <<6<<" "<<6*m+1-y; 
	}
	if(y>6*m && (y<7*m || y==7*m)) 
	{
		cout <<7<<" "<<y-6*m; 
	}
	if(y>7*m && (y<8*m || y==8*m)) 
	{
		cout <<8<<" "<<8*m+1-y; 
	}
	if(y>8*m && (y<9*m || y==9*m)) 
	{
		cout <<9<<" "<<y-8*m; 
	}
	if(y>9*m && (y<10*m || y==10*m)) 
	{
		cout <<10<<" "<<10*m+1-y; 
	}
	if(y>10*m && (y<11*m || y==11*m)) 
	{
		cout <<11<<" "<<y-10*m; 
	}
	return 0;
}
