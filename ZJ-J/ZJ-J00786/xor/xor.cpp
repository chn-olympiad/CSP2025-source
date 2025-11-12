#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+1;
long long n,k,a[N],mx=INT_MIN;
bool f=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)f=1;
	}
	if(f==0)
	{
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i]==k)++cnt;
		}
		cout<<cnt;
		return 0;
	}
	for(int ii=1;ii<=n;++ii)
	{
		long long ans=0;
		for(int i=ii;i<=n;i++)
		{
			long long tk=a[i];
			for(int j=i;j<=n;j++)
			{
				if(j!=i)tk^=a[j];	
				if(tk==k)
				{
					i=j;
					++ans;
					break;
				}
			}
		}
		mx=max(mx,ans);
	}
 	cout<<mx;
	return 0;	
}
/*
4 0
2 1 0 3
*/