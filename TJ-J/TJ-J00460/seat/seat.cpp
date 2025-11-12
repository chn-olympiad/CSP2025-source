#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int y=0;
    int vh=1;
    cin>>n>>m;
    int X=1,Y=1;
    const int N=n,M=m;
    int a[(N*M)];
    for(int i=0;i<n*m;i++)
    {
    	cin>>a[i];
	}
	for(int j=0;j<n*m;j++)
	{
		for(int k=j+1;k<n*m;k++)
		{
			if(a[j]<a[k])
			{
			int T;
			T=a[k];
			a[k]=a[j];
			a[j]=T;
			if(j==y)
			y=k;
			if(k==y)
			y=j;
			}
		}
	}
	for(int i=1;i<=y+1;i++)
	{
		if(i%(n*2)<n)
		{
		if(vh<n)
		{
		vh++;
		X++;	
		}
		}
		else
		{
			vh++;
			X--;
		}
		if(vh==n*2)
		{
			vh=0;
			Y++;
		}
		if(vh==n)
		{
			Y++;
		}
	}
	cout<<X<<" "<<Y;
}
