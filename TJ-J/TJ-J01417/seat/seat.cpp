#include<bits/stdc++.h>
using namespace std ;
long long n,m,a[101],ps,x,y,st,maxn,minn=214975836;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>st;
	for(int i=1;i<n*m;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	ps=maxn-st+1;
	int p=ps/n;
	ps%=n;
	x=p+1;
	y=ps+1;
    cout<<y<<' '<<x;
	return 0;
}
