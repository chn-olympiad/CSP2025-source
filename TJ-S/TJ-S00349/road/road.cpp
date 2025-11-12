#include<iostream>
using namespace std;
	
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int sum=0;
	int n,m,k;
	cin >> n >> m >> k;
	if(n%2!=0||m%2!=0)
	{
		return 0;
	}
	int a[10];
	for(int i=0;i<10;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<10;i++)
	{
		int d;
		cin >> d;
		int e=m*e;
		int f;
		cin >> f;
		int g=k*f;
		if(n%2!=0)
		{
			return 0;
		}
		if(a[i]-1>a[i])
		{
			sum=a[i];
		}
		
	}
	cout << sum;
	return 0;
} 
	
