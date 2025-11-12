#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,t[105],r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>t[i];
	}
	r=t[1];
	sort(t+1,t+1+m*n);
	int c;
	for(int i=n*m,j=1;i>=1;i--,j++)
	{
		if(t[i]==r)
		c=j;
	}
	int x,y;
	int a=n*2;
	y=c/n+1;
	if(c%n==0)
	y--;
	x=c-n*(y-1);
	if(y%2==0)
	x=m-x+1;
	cout<<y<<" "<<x;
	return 0;
 } 
