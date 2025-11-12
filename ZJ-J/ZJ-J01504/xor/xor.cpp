#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long a[500005];
bool f;
long long q,w;
long long ans,ANS=-1e18;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);	
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1)
			f=1;
	}
	long long i=0,j=0;
	if(f!=1)
	{
		printf("%lld",n/2);
	}
	else if(f==1)
	{
		while(i!=n)
		{
			i++;
			j=i;
			q=0;
			w=ans;
			while(j!=n+1)
			{	
				q=q^a[j];
				j++;
				if(q==k)
				{
					ans++;
					break;
				}		
			}
			if(w<ans)
				i=j-1;
		}
		printf("%lld",ans);
	}	
	return 0;
}

