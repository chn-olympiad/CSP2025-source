#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[500010];
int b[500010];
int vis[500010];
bool tzA=true;
bool tzB=true;
int sum1=0;
int lzd1;
int sum=0;
bool check(int l,int r)
{
	for(int i=l;i<=r;++i)
	{
		if(vis[i] == 1)
		{
			return false;
		}
	}
	for(int i=l;i<=r;++i)
	{
		vis[i] = 1;
	}
	return true;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		b[i] = a[i]^b[i-1];
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=1)
		{
			tzA=false;
//			printf("\n%lld:%lld\n",i,a[i]);
		}
		if(a[i]!=1&&a[i]!=0)
		{
			tzB=false;
		}
		if(a[i] == 1)++sum1;
	}
	if(tzA == true)
	{
//		printf("A\n");
		if(k == 0)
		{
			printf("%lld",n/2);
		}
		else
		{
			printf("%lld",n);
		}
		return 0;
	}
	
	if(tzB == true)
	{
//		printf("B:%lld\n",k);
		if(k == 1)
		{
			printf("%lld",sum1);
		}
		else
		{
			for(int i=1;i<=n;++i){
			
				if(a[i] == 1&&a[i+1] == 1)
				{
					lzd1++;
					i++;
				}
			}
			printf("%lld",n-sum1+lzd1);
		}
		return 0;
	}
	int c;

	int r;
	for(int i=1;i<=n;++i)
	{
		
		for(int l=1;l+i-1<=n;++l)
		{
			
			r = l+i-1;
			c = b[r]^b[l-1];	
			//printf("%lld %lld:%lld\n",l,r,c);
			if(c == k&&check(l,r))
			{
				//printf("WIN:%lld %lld\n",l,r);
				l = r;
				sum++;
				
			}
		}
	}
	printf("%lld",sum);
	return 0;
}
