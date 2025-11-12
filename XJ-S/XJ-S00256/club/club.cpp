#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long int n,a[N],b[N],c[N],flag[N],T;
long long int dfs(int q)
{
	long long int a1=0,a2=0,a3=0;
	for(long long int i=1;i<=n;i++)
	{
		if(flag[i]==1)
			a1++;
		if(flag[i]==2)
			a2++;
		if(flag[i]==3)
			a3++;
	}
	if(a1>n/2||a2>n/2||a3>n/2)
		return 0;
	if(q==0)
	{
		long long int ans=0;
		for(long long int i=1;i<=n;i++)
		{
			if(flag[i]==1)
				ans+=a[i];
			else if(flag[i]==2)
				ans+=b[i];
			else
				ans+=c[i];
		}
		return ans;
	}
	long long int sum1,sum2,sum3;
	flag[n-q+1]=1;
	sum1=dfs(q-1);
	for(int i=n-q+1;i<=n;i++)
		flag[i]=0;
	flag[n-q+1]=2;
	sum2=dfs(q-1);
	for(int i=n-q+1;i<=n;i++)
		flag[i]=0;
	flag[n-q+1]=3;
	sum3=dfs(q-1);
	return max(max(sum1,sum2),sum3);
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int cn=1;
		for(long long int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0)
				cn=0;
		}
		if(cn==1)
		{
			sort(a+1,a+1+n,cmp);
			int cnt=0;
			for(int i=1;i<=n/2;i++)
				cnt+=a[i];
			cout<<cnt<<endl;
			continue;
		}
		for(long long int i=1;i<=n;i++)
			flag[i]=0;
		cout<<dfs(n)<<endl;
	}
	return 0;
}
