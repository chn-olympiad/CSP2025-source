#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[500500],sum[500500];
bool vis[500500];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int len=1;len<=n;len++)
	{
		for(int i=1;i<=n-len+1;i++)
		{
			bool flag=1;
			for(int j=i;j<=i+len-1;j++)
			{
				if(vis[j])
				{
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				if((sum[i+len-1]^sum[i-1])==k)
				{
				//	cout<<i<<" "<<i+len-1<<" "<<(sum[i+len-1]^sum[i-1])<<endl;
					ans++;
					for(int j=i;j<=i+len-1;j++)
					{
						vis[j]=1;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}//20pts
//4 2
//2 1 0 3
//2

//4 3
//2 1 0 3
//2

//4 0
//2 1 0 3
//1