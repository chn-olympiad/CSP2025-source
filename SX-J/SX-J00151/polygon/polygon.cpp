#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,sum,maxx;
int a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		maxx=max(a[i],maxx);
	}
	if(sum>maxx*2)
	{
		cout<<1;
	}
	return 0;
}