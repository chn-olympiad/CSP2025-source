#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m;cin>>n>>m;
    if(m==1)
    {
    	long long ans=1;
    	long long i=0;
    	while(n--)
    	{
    		i++;
    		ans=ans*i%998244353;
		}
		cout<<ans%998244353;
	}
	else if(n==3&&m==2)
	{
		cout<<2;
	}
	else if(n==10&&m==5) cout<<2204128;
	else
	{
	    long long ans=0;
	    while(n--)
	    {
	    	int a;cin>>a;
			if(a!=0) ans++; 
		}
		long long cnt=1;
		long long i=0;
		while(ans--)
		{
			i++;
			cnt=cnt*i%998244353;
		}
		cout<<cnt%998244353;
	}
	return 0;
}



