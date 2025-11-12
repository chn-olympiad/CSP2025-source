#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,a[N],sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>a[3]*2) sum++;
	}
	else if(n<3) sum=0;
	cout<<sum;
	return 0;
}
