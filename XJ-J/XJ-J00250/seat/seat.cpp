#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b[101]={0},c[101]={0};
	cin>>n>>m;
	int a[n+1][m+1]={0};
	int r,f=0;
	for(int i=0;i<n*m;i++)
	{
		int nm;
		cin>>nm;
		if(f==0)r=nm;
		f=1;
		b[nm]++;
	}
	int lii=0;
	for(int i=0;i<=100;i++)
	{
		if(b[i]!=0)c[lii++]=i;
	}
	int x=0,y=0;
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<m;j++)
		{
		
		a[i][j]=c[j+i*m];
		cout<<a[i][j];
		if(a[i][j]==r)
		{
			x=i+1;
			y=j+1;
		}
		}
		cout<<endl;
	}
	cout<<y<<" "<<x;
	return 0;
 } 
