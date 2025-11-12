#include<bits/stdc++.h>
using namespace std;
long long int n,a[5005],maxn,sum;
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n==3)
	{
		maxn=max(max(a[1],a[2]),a[3]);
		sum=a[1]+a[2]+a[3];
		if(sum>maxn*2)
		cout<<1;
		else
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	
	return 0;
}
