#include<bits/stdc++.h>
using namespace std;
const int mod=1e9;
long long mp(long long x)
{
	long long c=1,a=2;
	while(x)
	{
		if(x%2==1)
			c=c*a%mod;
		x/=2,a=a*a%mod;
	}
	return c;
}
int main()
{
	cout<<mp(31);
	return 0;
}
//		int l=i+1,r =n-1,ans=-1;//在哪个点之前刚好不可以围成多边形 
//		while(l<=r)
//		{
//			int mid=(l+r)/2;
//			if(s[n]-s[mid-1]>a[i])//可以围成多边形 
//			{
//				ans=mid;
//				l=mid+1;
//			}
//			else	r=mid-1;
//		}
		//从n开始取要取到ans
//		printf("---%d %d\n",i,ans);
//		if(ans==-1)	continue;
/*
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n-2;i++)//任务:在i+1~n中任取任意根木棍,让它们的长度和大于i号木棍的长度 
	{
		int q=n-1;
		for(int p=n;p>=i+1;p--)
		{
			while(s[p]-s[q-1]<=a[i]&&q>=i+1)
				q--;
			//从p开始取一定要取到q 
			int len=max(q-i-1,0);
			if(q>=i+1)
			{
				sum=(sum+(1LL<<len)%mod)%mod;
//				for(int j=q;j<=p;j++)
//					printf("%d ",a[j]);
//				printf("\n");
			}
//			printf("%d %d %d %d\n",i,q,p,len*(len+1)/2+1);
		}
		q=i+1;
		for(int p=i+1;p<=n;p++)
		{
			while(s[q]-s[p-1]<=a[i]&&q<=n)
				q++;
			//从p开始取一定要取到q 
			int len=max(n-q,0);
			long long g=1LL<<len-len;
			if(q<=n)
				sum=(sum+g%mod)%mod;
//			printf("%d %d %d %d\n",i,p,q,g);
		}
	}
*/
