#include<bits/stdc++.h>
using namespace std;
int c[15][15];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,li,mi=1;
	cin>>n>>m>>x;
	for(int i=2;i<=n*m;i++)
	{
		cin>>li;
		if(li>x)
		{
			mi++;
		}
	}
	int t=(mi+n-1)/n;
	cout<<t<<" ";
	if(t%2==1)
	{
		cout<<n-(t*n-mi);
	}
	else
	{
		cout<<t*n-mi+1;
	}
	return 0;
}
