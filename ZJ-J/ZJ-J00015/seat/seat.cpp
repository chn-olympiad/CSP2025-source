#include<bits/stdc++.h>
using namespace std;
int n,m,R,r,x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;
	for(int i=1;i<=n*m-1;i++)
	{
		cin>>x;
		if(x>r)
		{
			R++;
		}
	}
	cout<<R/n+1<<" ";
	if((R/n+1)%2==1)
	{
		cout<<R%n+1;
	}
	else
	{
		cout<<n-R%n;
	}
}