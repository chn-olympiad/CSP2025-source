#include<bits/stdc++.h>
using namespace std;
long long a;

unsigned long long res1 = 1;
unsigned long long res2 = 1;
int n,m;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("emplpy.out","w",stdout);
	cin>>n>>m;
	for(int i=n;i>=n-m+1;--i)
	{
		res1*=i;
	}
	for(int i=m;i>=1;--i)
	{
		res2*=i;
	}
	unsigned long long f = res1/res2%998244353;
	
	cout<<f; 
	return 0;
} 
