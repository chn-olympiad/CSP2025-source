#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
#define int long long
//a xor b = (a + b) % 2^n
//nlogn
//dp
int n,k;
int sum[500010];
int a[500010];
int dp[500010];//i=i zhi1 qian2 (bao1 kuo4 i)de4 qu1 jian1 shu4
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i]=max(dp[j],dp[i]);//bu4 xin1 kai1 qu1 jian1 [x x x] [x] x x i
			int p=sum[i]^sum[j-1];
			if(p==k)//fa1 xian4 ke2 xin1 kai1 qu1 jian1 j->i
			{
			//	cout<<j<<" "<<i<<endl;
				dp[i]=max(dp[i],dp[j-1]+1);//shi4 fou3 dan1 kai1 qu1 jian1
			}
		}
	}
//	for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
	cout<<dp[n];
	return 0;
}
