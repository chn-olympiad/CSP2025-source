#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,n1=0,m1=0;
	cin>>n>>m;
	int cnt=0;
	int mx=-1,min=100000000;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		if(a[i]>mx)
		{
			mx=a[i];
			cnt++;
			
		}
		
	}
	for(int i=1;i<=cnt;i++)
	{
		n1++;
		if(n1>=n)
		{
			m1++;
		}
		if(m1>=m)
		{
			n1=n1-1;
		}
	}
	cout<<m1<<" "<<n1;
} 
