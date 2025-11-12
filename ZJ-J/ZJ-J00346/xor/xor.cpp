#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,s[500005],q[500005],k,ans=-1,cnt=0,sum=0;
int solve(int x)
{
	int l=x,flag=0,sum=0,cnt=0;
	while(l<=n)
	{
		flag=0,sum=0;
		for(int i=l;i<=n;i++)
		{
			sum^=s[i];
			if(sum==k) {flag=1,cnt++,l=i+1;break;}
		}
		if(!flag) l++;
	}
	return cnt;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&s[i]);
	for(int i=1;i<=n;i++) sum+=s[i];
	if(sum==0) cout<<n/2;
	else if(sum<=n) cout<<sum;
	else//бр╢Р 
	{
		q[1]=s[1];
		for(int i=2;i<=n;i++) q[i]=q[1]^s[i];
		for(int i=1;i<=n;i++)
			ans=max(ans,solve(i));
		cout<<ans;
	}
	return 0;
}

