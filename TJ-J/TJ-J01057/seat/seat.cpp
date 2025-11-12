#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,number,text;
	cin>>n>>m;
	short xy [n*m+5];
	for (int i=0;i<n*m;i++)
	{
		cin>>xy[i];
	}
	text=xy[0];
	sort(xy,xy+n*m);
	for (int i=n*m;i>=1;i--)
	{
		if(xy[i-1]==text)
		{
			number=n*m-i+1;
			break;
		}
	}
	
	if (number%n==0)
		c=number/n;
	else
		c=number/n+1;
	
	if (c%2==0)
	{
		r=n-number%n+1;
	}
	else
	{
		if (number%n!=0)
		r=number%n;
		else
		r=n;
	}
	cout <<c<<" "<<r;
	return 0;
} 
