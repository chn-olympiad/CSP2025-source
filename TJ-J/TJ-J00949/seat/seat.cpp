#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int a[100101010];
int main()
{
	//preopen("seat.in","r",stdin);
	//preopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	if(n==1&&m==1)
	{
		cout<<1<<" "<<1;
		return 0;
	}
	int r=a[0];
	int r1;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(a[i]==r)
		{
			r1=i+1;
			i=n*m;
		}
	}
	int x=r1/n;
	int y;
	r1=r1%n;
	if(x%2==1)
	{
		y=r1;
	}
	else
	{
		y=n+1-r1;
	}
	cout<<x<<" "<<y;
	return 0;
}
