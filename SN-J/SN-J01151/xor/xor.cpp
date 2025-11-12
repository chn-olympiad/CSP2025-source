#include<bits/stdc++.h>
using namespace std;
long long a[1048580],f[1048580];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
			f[i]=1;
		}
	}
	int left=1,right=1,m;
	while(f[left]==1)
	{
		left++;
		right++;
	}
	while(right<=n&&left<=right)
	{
		m=a[left];
		for(int i=left+1;i<=right;i++)
		{
			m=m xor a[i];
		}
		
		if(m!=k) 
		{
			right++;
			if(f[right]==1)
			{
				right++;
				left=right;
			}
		}
		if(m==k)
		{
			ans++;
			right++;
			left=right;
		}
	}
	cout<<ans;
	return 0;
}
