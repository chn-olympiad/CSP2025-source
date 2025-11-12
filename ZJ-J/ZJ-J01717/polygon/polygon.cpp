#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],ans=1;
bool v[N];
int cmp(int A,int B)
{
	return A>B;
}
int f(int n,int k,int x)
{
	int sum=0;
	if(x==k+1)
		sum++;
	else
	{
		for(int i=a[i-1];i<=n;i++)
		{
			if(v[i]==0)
			{
				v[i]=1;
				f(n,k,x+1);
				v[i]=0;
			}
		}
	}
	return sum%998244353;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+n+1,cmp);
	if(n<=3)
	{
		if(n<=2)
		    ans=0;
		else
		{
			if(a[1]+a[2]+a[3]>2*a[1])
		        ans=1;
		    else
		        ans=0;
		}	        
	}
	else 
	{
		int max=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>max)
			    max=a[i];
		}
		if(max==1)
		{
			for(int i=3;i<=n-1;i++)
				ans+=(f(n,i,1))%998244353;
		}
	}
	cout<<ans%998244353;
	return 0;
}
