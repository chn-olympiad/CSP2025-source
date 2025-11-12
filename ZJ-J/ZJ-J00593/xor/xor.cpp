#include<bits/stdc++.h>
using namespace std;
const int N=1048577;
int bucket[N],pre[N],desire[N];
int a[N];
int k,n;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//int nowbucket=0;
	int maxbucket=0;
	int ans=0;
	cin>>n>>k;
	bucket[0]=1;
	//cerr<<sizeof(bucket);
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		//desire[i]=pre[i]^k;
		int desire=pre[i]^k;
		if (bucket[desire])
		{
			ans++;
			//bucket[nowbucket][desire[i]]--;
			//nowbucket++;
			memset(bucket,0,(maxbucket+3)*4);
			//maxbucket=0;
		}
		bucket[pre[i]]++;
		maxbucket=max(pre[i],maxbucket);
		
	}
	cout<<ans;
	return 0;
	
}
