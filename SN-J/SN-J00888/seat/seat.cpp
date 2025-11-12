#include<bits/stdc++.h>
#include<fstream>
std::ifstream cin("seat.in");
std::ofstream cout("seat.out");
int main()
{
	int n,m;
	cin>>n>>m;
	int R;
	int sh[105];
	int b[12][12];
	int a[105];
	cin>>R;
	for(int i=0;i<n*m-1;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n*m;i++)
	{
		if(a[i+1]>a[i])
	    {
	        int sum;
		    sum=n[i];
		    a[i]=a[i+1];
		    a[i+1]=a[i];
	    }
	}
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				b[j][i]=a[j];
			}
			
		}
	cout<<'1'<<' '<<'2';
	return 0;
}
