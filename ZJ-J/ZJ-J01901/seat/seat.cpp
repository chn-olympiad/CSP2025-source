#include<bits/stdc++.h>
using namespace std;
int cnt[101];
int main()
{
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int a[m*n+1];
	int xy=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		xy=a[1];
		cnt[a[i]]++;
	}
	int c=0;
	for(int i=100;i>=1;i--)
	{
		if(i==xy)
		{
			c++;
			break;
		}
		c=c+cnt[i];
	}
	int x,y;
	if(c%n==0)
		x=c/n;
	if(c%n!=0)
		x=c/n+1;
	if(x%2==1 && c%n==0)
		y=n;
	if(x%2==1 && c%n!=0)
		y=c%n;
	if(x%2==0 && c%n==0)
		y=1;
	if(x%2==0 && c%n!=0)
		y=n-c%n+1;
	cout<<x<<" "<<y;
	return 0;
}
