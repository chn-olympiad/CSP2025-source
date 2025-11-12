#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[102400],b[102400],c[102400];
bool cmp(int x,int y)
{
	return x>y;
}
vector<int>ind[4];
int cnt[4],ans,book[102400];
int na[102400],nb[102400],nc[102400];
int n,num[4][102400];
void dfs(int dep,int sum,int a,int b,int c)
{
	if(dep>n)
	{
		ans=max(ans,sum);
		return;
	}
	if(a*2<n) dfs(dep+1,sum+num[1][dep],a+1,b,c);
	if(b*2<n) dfs(dep+1,sum+num[2][dep],a,b+1,c);
	if(c*2<n) dfs(dep+1,sum+num[3][dep],a,b,c+1);
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;int flag=1;ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&num[1][i],&num[2][i],&num[3][i]);
			if(num[3][i]!=0)
				flag=0;
		}
		if(n<=15)
		{
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		else if(flag)
		{
			sort(num[1]+1,num[1]+n+1,cmp);
			for(int i=1;i<=n/2;i++)
				ans+=num[1][i];
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			a[i]=na[i]=num[1][i];
			b[i]=nb[i]=num[2][i];
			c[i]=nc[i]=num[3][i];
		}
		sort(na+1,na+n+1,cmp);
		sort(nb+1,nb+n+1,cmp);
		sort(nc+1,nc+n+1,cmp);
		int ans1=0,ans2=0,ans3=0,ans4=0;
		memset(book,0,sizeof(book));
		for(int i=1;i<=n/2;i++)
			ans1+=na[i],book[i]=1;
		for(int i=1;i<=n;i++)
			if(book[i]==0)
				ans1+=max(b[i],c[i]);
		memset(book,0,sizeof(book));
		for(int i=1;i<=n/2;i++)
			ans2+=nb[i],book[i]=1;
		for(int i=1;i<=n;i++)
			if(book[i]==0)
				ans2+=max(a[i],c[i]);
		memset(book,0,sizeof(book));
		for(int i=1;i<=n/2;i++)
			ans3+=nc[i],book[i]=1;
		for(int i=1;i<=n;i++)
			if(book[i]==0)
				ans3+=max(a[i],b[i]);
		int cnta=0,cntb=0,cntc=0;
		for(int i=1;i<=n;i++)
			if(a[i]>b[i]&&a[i]>c[i])
			{
				cnta++;
				if(cnta*2>n)
				{
					ans4=0;
					break;
				}
				ans4+=a[i];
			}
			else if(b[i]>c[i])
			{
				cntb++;
				if(cntb*2>n)
				{
					ans4=0;
					break;
				}
				ans4+=b[i];
			}
			else
			{
				cntc++;
				if(cntc*2>n)
				{
					ans4=0;
					break;
				}
				ans4+=c[i];
			}
		ans=max(max(ans1,ans2),max(ans3,ans4));
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
