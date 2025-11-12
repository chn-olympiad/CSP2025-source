#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long num=0;
	int n,m;
	cin>>n>>m;
	num=m;
	for(int i=m-1;i>0;i--)
	{
		num*=i;
	}
	cout<<num*(n-m+1)%998244353;
	
	
	
	
	return 0;
}
