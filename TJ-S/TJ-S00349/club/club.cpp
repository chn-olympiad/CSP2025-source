#include<iostream>
using namespace std;
	
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int num;
	int sum=0;
	int n;
	cin >> n;
	if(n%2!=0)
	{
		return 0;
	 } 
	
	int t;
	cin >>t;
	int a[3];
	int c;
	int d;
	int e;
	cin >>c >> d >> e;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]>=n/2)
		{
			break;
		}
		else
		{
			sum++;	
		}
		if(a[i]-1>a[i])
		{
			num=a[i]-1;
			
		}
	}
	cout << sum;
	return 0;
} 
	
