#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,x[500010],a[500010],sum[500010],l,r=1e9,mid;
bool f[500010];
bool check(long long mid)
{
	int cnt=0;
	for(int i=n;i>=1;i--)
	{
		for(int j=i;j>=1;j--)
		{
			if(a[j]==k&&j!=i) break;
			if((long long)(sum[i]^sum[j-1])==k)
			{
				i=j-1;
				cnt++;
				break;
			}
		}
	}
	if(cnt>=mid) return 1;
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
		x[a[i]]++;
		sum[i]=(long long)(sum[i-1]^a[i]);
	}	
	if(x[1]==n&&k==0)
	{
		cout<<n/2;
		return 0;
	}
	else if(k<=1)
	{
		if(k==1) cout<<x[1];
		else
		{
			long long s=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) s++;
				if(a[i]==1&&a[i+1]==1) s++,i++;
			}
			cout<<s;
		}
		return 0;
	}
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<r;
	return 0;
}


