#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r=n*m;
	int cj[r];
	for(int i=0;i<r;i++)
	{
		cin>>cj[i];
	}
	int R=cj[0];
	sort(cj,cj+r);
	int pm=0;
	for(int i=r-1;i>=0;i--)
	{
		pm++;
		if(cj[i]==R)
		{
			break;
		}
	}
	if(pm==1)
	{
		cout<<"1 1";
		return 0;
	}
	int x;
	if(pm%n>0)
	{
		cout<<pm/n+1<<" ";
		x=pm/n+1;
	}
	else if(pm%n==0)
	{
		cout<<pm/n<<" ";
		x=pm/n;
	}
	if(x==1)
	{
		cout<<pm;
		return 0;
	}
	if(x%2==1)
	{
		cout<<pm%n;
	}
	else
	{
		cout<<n-pm%n+1;
	}
}
