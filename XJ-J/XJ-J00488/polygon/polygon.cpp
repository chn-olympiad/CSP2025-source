#include<bits/stdc++.h>
using namespace std;
int arr[5100];
int main()
{
	freopen(" polygon.in","r",stdin);
	freopen(" polygon.out","w",stdout);
	int n,a=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	if(n==3)
	{
		if(arr[0]>=arr[1])
		{
			a=arr[0];
			if(arr[0]>arr[2])
			{
				a=arr[0];
			}
			else if(arr[0]<arr[2])
			{
				a=arr[2];
			}
		}
		else if(arr[0]<=arr[1])
		{
			a=arr[1];
			if(arr[1]>arr[2])
			{
				a=arr[1];
			}
			else if(arr[1]<arr[2])
			{
				a=arr[2];
			}
		}
		int num=arr[0]+arr[1]+arr[2];
		if(num>a*2)
		{
			cout<<"1";
			return 0;
		}
		else if(num<=a*2)
		{
			cout<<"0";
			return 0;
		}
	}
	else 
	{
		
	}
	return 0;
}
