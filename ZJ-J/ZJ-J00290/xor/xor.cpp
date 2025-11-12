	#include<bits/stdc++.h>
//	#define int long long
	using namespace std;
	const int N=2e5+1;
	int a[N],b[N],n,k,ans;
	void dfs(int x,int sum)
	{
		if(x==n)
		{
			ans=max(sum,ans);
			return;
		}
		if(b[x])
		{
			dfs(b[x]+1,sum+1);
		}
		dfs(x+1,sum);
	}
	signed main()
	{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
//		freopen("xor.in","r",stdin);
//		freopen("xor.out","w",stdout);
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			int a1=a[i];
			if(a[i]==k)
			{
				b[i]=i;
				continue;
			}
			for(int j=i+1;j<=n;j++)
			{
				if(a1==k)
				{
					b[i]=j;
					break;
				}
				if(a1<k)
				{
					break;
				}
				a1=a1^a[j];
			}
		}
		dfs(0,0);
		cout<<ans;
		return 0;
	}
	/*
	4 0 2 1 0 3

	*/
