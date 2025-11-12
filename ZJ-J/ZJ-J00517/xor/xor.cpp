#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
long long k,q;
int n,x,r=0;
long long a[500005];
int y,qwe=0,cnt=0,ans,daan=0;
int main()
{
	freopen(xor.in,"r",stdin);
	freopen(xor.out,"w",stdout);
	cin>>n>>k;
	a[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=a[i-1]) qwe++;
		if(a[i]>1) r++;
		if(a[i]==1) cnt++;
		if(a[i]==k) daan=1;
	}
	if(qwe==0) 
	{
	  cout<<n;
	  return 0;
    }   
    else if(r==0) 
	{
		if(cnt%2!=0) cout<<n;
	    else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) ans=n-i;
			}
			for(int i=n;i>=1;i--)
			{
				if(a[i]==1) ans=max(ans,i-1);
			}
		}
		cout<<ans;
		return 0;
    }   
    else 
    {
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=i+1;j<=n;j++)
    		{
    			q=a[i]^a[j];
    			if(q==k) daan=max(daan,j-i+1);
    			if(j==n&&q==k) 
    			{
    				cout<<daan;
    				return 0;
				}
				if(daan>=n-i)
				{
					cout<<daan;
					return 0;
				}
			}
		}
		cout<<daan;
	}
	return 0;
}
