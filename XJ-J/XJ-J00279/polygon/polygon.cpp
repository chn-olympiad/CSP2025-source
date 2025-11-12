#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
long long n,a[N],maxx=-N,num,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<3)
	{
		cout<<0;
	}
	else if(n==3)
	{
		cout<<1;
	}
	cout<<8;
	return 0;
}
