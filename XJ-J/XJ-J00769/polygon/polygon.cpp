#include<bits/stdc++.h>
using namespace std;
long long int n,i,l,t,sum,a[100005],v[100005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=3;i<=n;i++)
	{
		for(l=1;l<=n;l++)
		{
			v[l]=a[l];
			sort(v+1,v+1+n,greater<int>());
			sum+=a[l];
			if(sum>v[1]*2)
			t++;
			if(t>i)
			break;
		}
	}
	cout<<t%998244353;
}
