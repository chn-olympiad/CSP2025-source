#include<bits/stdc++.h>
using namespace std;
long long n,q;
char a[2010][2010],b[2010][2010],c[2010],d[2010],s[2010],s2[2010],len1,len2,ans;
bool check(long long k,long long id)
{
	for(long long i=0;i<len1;i++)
	{
		s2[i]=s[i];
	}
	for(long long i=k;i<=k+len2-1;i++)
	{
		if(s2[i]!=a[id][i-k])
		{
			return false;
		}
	}
	for(long long i=k;i<=k+len2-1;i++)
	{
		s2[i]=b[id][i-k];
	}
	for(long long i=0;i<len1;i++)
	{
		if(s2[i]!=d[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(long long i=1;i<=q;i++)
	{
		cin>>c>>d;
		len1=strlen(c),len2=strlen(d),ans=0;
		if(len1!=len2)
		{
			printf("0\n");
			continue;
		}
		for(long long j=1;j<=n;j++)
		{
			len2=strlen(a[j]);
			if(len2>len1)
			{
				continue;
			}
			for(long long k=0;k<len1;k++)
			{
				s[k]=c[k];
			}
			for(long long k=0;k<len1-len2+1;k++)
			{
				if(s[k]==a[j][0])
				{
					if(check(k,j))
					{
						ans++;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
