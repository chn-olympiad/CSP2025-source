#include<bits/stdc++.h>
using namespace std;
int n,m,a=0,c=0,e=0;
int b[105]; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	a=b[1];
	for(int i=1;i<=n*m;i++)
	{
		if(b[i]>=a)
		{
			c++;
		}
	}
	//cout<<c;
	int t=c%n;
	int d=(c-t)/n;
	if(d%2==1)
	{	
		if(t>0)
			e=m-t+1;
		else
		{
			e=(c-1)%n+1;
			d--;
		}
	}
	else e=t;
	cout<<d+1<<" "<<e;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
