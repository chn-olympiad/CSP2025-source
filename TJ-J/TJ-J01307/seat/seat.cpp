#include <bits/stdc++.h>
using namespace std;
int m,n,c,aa,l,h,hh;
int arr[101];

bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>arr[i];
	}
	aa=arr[0];
	
	sort(arr,arr+n*m,cmp);
	
	for(int i=0;i<n*m;i++)
	{
		if(arr[i]==aa)
		{
			c=i+1;
			break;
		}
			
	}
	
	l=c/n;
	h=c%n;

	if(h>0)
	{
		if((l+1)%2==0)
		{
			hh=n-h+1;
		}
		else
			hh=h;
		l++;
	}
	else
	{
		hh=n;
	}
	
	cout<<l<<" "<<hh;
		
	return 0;
}

/**
3 3
94 95 96 97 98 99 100 93 92
**/
