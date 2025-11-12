#include<bits/stdc++.h>
using namespace std;
int m[5005];
bool st(int a,int b)
{
	return a<b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a;
	long long ans=0;
	cin>>n;
	for(int i=0;i<n;i++)
	scanf("%d",&m[i]);
	sort(m,m+n,st);
	for(int i=2;i<n;i++)
	{
		a=0;
		for(int j=0;j<i;j++)
		a+=m[j];
		if(a>m[i])
		{
			ans++;
			a-=m[i];
			for(int j=0;j<i;j++)
			{
				if(m[j]>=a)
			    {
				    ans+=j;
				    break;
			    }
			    if(j==i-1)
			    ans+=j;
			}
		}
	}
	ans%=998244353;
	printf("%lld",ans);
	return 0;
}
