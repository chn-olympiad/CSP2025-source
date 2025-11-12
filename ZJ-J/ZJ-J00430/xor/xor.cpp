#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5+5;
int a[maxn],ans;
int dp[maxn];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dp[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1] xor a[i];
	}
	int u=0;
	for(int i=1;i<=n;i=(u>i?u+1:i+1))
	{
		u=0;
		for(int j=i;j<=n;j++)
		{
			if(i==j) 
			{
				if(a[j]==k) 
				{
					ans++;
					u=j;
					break;
				}
			}
			else
			{
				int w=i;
				while((dp[j] xor dp[w-1]) != k && w<j) w++;
				if(w!=j)
				{
					ans++;
					u=j;
					break;
				}
				else
				{
					if(a[w]==k)
					{
						ans++;
						u=j;
						break;
					}
				}
			} 
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
