#include<bits/stdc++.h>
using namespace std;
long long int a[1000005],v[1000005],s[25];
int main()
{
	long long int i,j,n,k,ans=0,c=0,t,flag=0;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
	{	
	if(a[i]==k)	
	{
	ans++;
	v[i]=1;	
	}
	}
	for(i=1;i<=n;i++)
	{
	flag=0;
	if(v[i]==0)	
	for(j=i+1;j<=n;j++)
	{	
	if(v[j]==1)
	{
	flag=1;	
	break;	
	}
	if(c!=0)	
	{
	if(c xor a[j]==k)	
	{
	c=0;	
	ans++;
	v[j]=1;
	v[i]=1;
	break;	
	}	
	else	
	c+=a[j];	
	}
	else
	{
	c=a[i];	
	if(c xor a[j]==k)	
	{
	c=0;	
	ans++;
	v[j]=1;
	v[i]=1;
	break;	
	}	
	else
	c+=a[j];
	}
	}
	if(flag==1)
	i=j+1;	
	}
	printf("%lld",ans);
	return 0;
}
