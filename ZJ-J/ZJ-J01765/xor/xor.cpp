#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans,pri[N],l,r,mid;
int A()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(k==1 && a[i]==1)
			ans++;
		if(k==0)
		{
			if(a[i]==0)
				ans++;
			if(a[i]==1 && a[i+1]==1)
			{
				ans++;
				i++;
			}
		}
	}
	return ans;
}
bool check(int mid)
{
	int x=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=x;j--)
		{
			if((pri[i]^pri[j])==k)
			{
				mid--;
				if(!mid)
					return 1;
				x=i;
				break;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pri[i]=pri[i-1]^a[i];
	}
	if(k<=1)
	{
		cout<<A();
		return 0;
	}
	l=0,r=n;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l;
	return 0;
}
