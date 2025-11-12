#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,sum=1,q=1,w=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<=n*m-1;i++)
	{
		cin>>b;
		if(b>a)
		{
			sum++;
		}
	}
	while(sum>n-1)
	{
		if(sum>=2*n)
		{
			sum-=2*n;
			q+=2;
			w=1;
		}
		else if(sum>=n)
		{
			sum-=n;
			q+=1;
			w=m;
		}
	}
	w+=sum-1;
	cout<<q+w/(n+1)<<" "<<w%(n+1)+w/(n+1);
	return 0;
}
