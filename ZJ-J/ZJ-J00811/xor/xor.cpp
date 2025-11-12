#include<bits/stdc++.h>
using namespace std;
const int slen=5e5+10;
int a[slen],qzh[slen];
bool f[slen];
bool check(int a,int b)
{
	for(int i=a;i<=b;i++)
	{
		if(f[i]==1)
			return 0;
		f[i]=1;
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1)	qzh[i]=qzh[i-1]^a[i];
		else	qzh[i]=a[i];
		if(k==1&&a[i]==1)	ans++;	
	}
	if(k==1)
	{
		cout<<ans;return 0;
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{	
			if(i==j&&a[i]==k)
			{
				ans++;
				f[i]=1;
			}
			if((qzh[i]^qzh[j])==k&&i!=j&&qzh[i]!=qzh[j])
			{
				if(check(min(j+1,i),max(i,j+1))==1)	ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}