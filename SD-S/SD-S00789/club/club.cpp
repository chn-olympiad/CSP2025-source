#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
const int M=105;
int t,n,ans;
int a[N][4];
int read()
{
	int d=1,k=0;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9'||ch=='-'))
		ch=getchar();
	if(ch=='-')
	{
		d=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		k=k*10+ch-'0';
		ch=getchar();
	}
	return d*k;
}
int getsum()
{
	int sum=0;
	for(int i=1;i<=n;i++)
		sum+=a[i][a[i][0]];
	return sum;
}
void dfs(int k)
{
	if(a[0][1]>n/2||a[0][2]>n/2||a[0][3]>n/2)
		return;
	if(k==n+1)
		if(a[0][1]<=n/2&&a[0][2]<=n/2&&a[0][3]<=n/2)
			ans=max(ans,getsum());
	for(int i=1;i<=3;i++)
	{
		a[0][i]++;
		a[k][0]=i;
		dfs(k+1);
		a[0][i]--;
		a[k][0]=0;
	}
}
int cmp(int x,int y)
{
	return x>y;
}
void dfss2(int k)
{
	if(a[0][1]>n/2||a[0][2]>n/2||a[0][3]>n/2)
		return;
	if(k==n+1&&a[0][1]==n/2)
		ans=max(ans,getsum());
	for(int i=1;i<=2;i++)
	{
		a[0][i]++;
		a[k][0]=i;
		dfs(k+1);
		a[0][i]--;
		a[k][0]=0;
	}
}
void dfss3(int k)
{
	if(a[0][1]>n/2||a[0][2]>n/2||a[0][3]>n/2)
		return;
	if(k==n+1&&a[0][1]==n/2)
		ans=max(ans,getsum());
	for(int i=1;i<=3;i++)
	{
		if(i==2)
			continue;
		a[0][i]++;
		a[k][0]=i;
		dfs(k+1);
		a[0][i]--;
		a[k][0]=0;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--) 
	{
		n=read();
		for(int i=1;i<=n;++i)
		{
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
		}
		int flag2=0,flag3=0;
		for(int i=1;i<=n;++i)
		{
			if(a[i][2])
				flag2=1;
			if(a[i][3])
				flag3=1;
		}
		if(flag2&&flag3)
		{
			ans=0;
			dfs(1);
			printf("%d\n",ans);
			flag2=0;
			flag3=0;
		}
		else if(flag2)
		{
			ans=0;
			dfss2(1);
			printf("%d\n",ans);
			flag2=0;
		}
		else if(flag3)
		{
			ans=0;
			dfss3(1);
			printf("%d\n",ans);
			flag3=0;
		}
		else
		{
			int sum=0;
			int b[N];
			for(int i=1;i<=n;++i)
				b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;++i)
				sum+=b[i];
			printf("%d\n",sum);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
