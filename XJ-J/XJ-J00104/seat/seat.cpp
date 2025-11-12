#include<bits/stdc++.h>
using namespace std;
int n,m,i=1,k=1,t,t1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>t1;
	for(int j=2;j<=n*m;j++)
	{
		cin>>t;
		if(t>t1)
		{
			if(k%2==1) i++;
			else i--;
		}
		if(i>n)
		{
			i=n;
			k++;
		}
		else if(i<1)
		{
			i=1;
			k++;
		}
	}
	cout<<k<<" "<<i;
	return 0;
} 
