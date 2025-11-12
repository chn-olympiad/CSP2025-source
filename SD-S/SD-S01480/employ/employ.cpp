#include<bits/stdc++.h>
using namespace std;
string s;
int n,m,a[510],p[510],b[510];
long long ans=1;
bool flag=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ans=ans*i%998244353;
		if(s[i]=='0')	flag=1;
	}
	if(!flag)
	{
		printf("%lld",ans);
		return 0;
	}
	if(ans<=100000000)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			p[i]=i;
		}
		do
		{
			int cnt=0,mm=0;
			for(int i=1;i<=n;i++) b[p[i]]=a[i];
			for(int i=1;i<=n;i++)
			{
				if(cnt>=b[i]||s[i]=='0')	cnt++;
				else 						mm++;
			}
			if(mm>=m)	ans++;
		}
		while(next_permutation(p+1,p+n+1));
		printf("%lld",ans);
	}
	else printf("%lld",ans);
	return 0;
}


