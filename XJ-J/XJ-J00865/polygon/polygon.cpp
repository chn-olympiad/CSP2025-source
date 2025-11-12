#include<bits/stdc++.h> 
using namespace std;
long long int n,a[15],i,s;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(a[1]+a[2]+a[3]>=2*max(max(a[1],a[2]),max(a[2],a[3])))
	cout<<1;
	return 0;
}
