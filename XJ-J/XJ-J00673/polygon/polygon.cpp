#include<bits/stdc++.h>
using namespace std;
long long int n,a[100005],i,maxn=-1,sum;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		if(maxn<a[i])
		maxn=a[i];
	} 
	if(sum>2*maxn)
	cout<<"1";
	else
	cout<<"0";
	return 0;
}
