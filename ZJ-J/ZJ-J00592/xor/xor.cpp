#include<bits/stdc++.h>
using namespace std;
int inline read()
{
	int sum=0;
	char s=getchar();
	while('0'>s&&s>'9')
		s=getchar();
	while('0'<=s&&s<='9')
	{
		sum=sum*10+s-'0';
		s=getchar();
	}
	return sum;
}
int a[500001],f[500001];
map<int,int> s;
int dfs(int j,int sum)
{
	if(f[j])
		return f[j];
	int i;
	for(i=j-1;i>0;i--)
		if(s[i])
			f[j]=max(f[j],dfs(s[i],sum+1)+1);
	return f[j];
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,i,j,t;
	n=read();
	k=read();
	for(i=1;i<=n;i++)
	{
		t=read();
		a[i]=a[i-1]^t;
	}
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			if((a[j]^a[i-1])==k)
			{
				if(s[j]==0)
					s[j]=i;
				else
					s[j]=max(s[j],i);
				break;
			}
	cerr<<dfs(n+1,0);
	return 0;
}
