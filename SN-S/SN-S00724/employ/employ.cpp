#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
    
		long long sum=1;
		for(int i=1;i<=n;i++)
		{
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;
	
	return 0;
}
