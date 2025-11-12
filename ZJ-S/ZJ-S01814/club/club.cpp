#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int T,n,ans,flag1,flag2,flag3,ma;
int a[N][4],b[N],vis[10];
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
void dfs(int t,int sum)
{
	if (t==n+1)
	{
		ma=max(ma,sum);
		return ;
	}
	if (vis[1]<n/2)
	{
		vis[1]++;dfs(t+1,sum+a[t][1]);vis[1]--;
	}
	if (vis[2]<n/2)
	{
		vis[2]++;dfs(t+1,sum+a[t][2]);vis[2]--;
	}
	if (vis[3]<n/2)
	{
		vis[3]++;dfs(t+1,sum+a[t][3]);vis[3]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while (T--)
	{
		n=read();
		for (int i=1;i<=n;i++)
		{
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
		}
		flag1=flag2=flag3=1;
		for (int i=1;i<=n;i++)
		{
			if (a[i][1]!=0)	flag1=0;
			if (a[i][2]!=0)	flag2=0;
			if (a[i][3]!=0)	flag3=0;
		}
		if (flag1==1 && flag2==1)
		{
			for (int i=1;i<=n;i++)	b[i]=a[i][3];
			sort(b+1,b+1+n);
			ans=0;
			for (int i=n/2+1;i<=n;i++)	ans+=b[i];
			cout<<ans<<"\n";continue;
		}
		if (flag1==1 && flag3==1)
		{
			for (int i=1;i<=n;i++)	b[i]=a[i][2];
			sort(b+1,b+1+n);
			ans=0;
			for (int i=n/2+1;i<=n;i++)	ans+=b[i];
			cout<<ans<<"\n";continue;
		}
		if (flag2==1 && flag3==1)
		{
			for (int i=1;i<=n;i++)	b[i]=a[i][1];
			sort(b+1,b+1+n);
			ans=0;
			for (int i=n/2+1;i<=n;i++)	ans+=b[i];
			cout<<ans<<"\n";continue;
		}
		ma=-2e9;
		dfs(1,0);
		cout<<ma<<"\n";
	}
	return 0;
}
