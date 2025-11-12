#include <bits/stdc++.h>
using namespace std;
const int N=15;
int a[105];
int n,m,sR;
int C,R;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sR=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	int r;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sR)
		{
			r=i;
			break;
		}
	}
	C=(r+n-1)/n;
	R=(r+n-1)%n+1;
	if(C%2==0)
	{
		R=n+1-R;
	}
	cout<<C<<" "<<R;
	return 0;
} 
