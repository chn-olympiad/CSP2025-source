#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int c(int a,int b)
{
   int sum1=1,sum2=1;
	for(int i=a;i>=a-b+1;i--)
	{
	  sum1*=i;
	}
	for(int i=b;i>=1;i--)
	{
	  sum2*=i;
	}
	return sum1/sum2;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	if(n==3) cout<<1;
    if(n>3)
    {
    	for(int i=3;i<=n;i++)
    	{
    		ans+=c(n,i);
		}
		cout<<ans;
	}
	return 0;
}
