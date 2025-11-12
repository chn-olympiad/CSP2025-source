#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
const int maxa=2e6+5;
int n,k,a[maxn],p,mp[maxa],ans,LST;
int read()
{
	int n=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')n=n*10+c-'0',c=getchar();
	return n*f;
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	mp[0]=1;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		p^=a[i];
		if(mp[p^k]>LST)
		{
			++ans;	
			LST=i;
		}
		mp[p]=i+1;
	}
	printf("%lld",ans);
	return 0;
}

