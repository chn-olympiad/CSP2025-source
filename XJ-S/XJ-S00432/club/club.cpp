#include<bits/stdc++.h>
using namespace std;
long long int x[1000005],y[1000005],z[1000005];
int main()
{
	long long int a,b,c,i,n,t,ans,l;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
	a=1;
	ans=0;
	scanf("%lld",&n);	
	for(i=1;i<=n;i++)	
	{
	scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);		
	}	
	l=n/2;
	sort(x+1,x+1+n);	
	for(i=n;i>=1;i--)	
	if(a<=l)
	{
	ans+=x[i];		
	a++;		
	}
	cout<<ans<<endl;	
	}
	return 0;
}
