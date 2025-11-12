#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 200005
using namespace std;
int a[MAXN][4],cnt[4],b[MAXN],c[MAXN];
bool cmp(int x,int y)
{
	return x>y;
}
long long ans=0,maxn=0,n;
void dfs(int pos)
{
	if(cnt[1]>n/2||cnt[2]>n/2||cnt[3]>n/2)
	{
		return; 
	}
	if(pos>n)
	{
		if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
		{
			for(int i=1; i<=n; i++)
			{
				ans+=b[i];
			}
			if(maxn<ans)
			{
				maxn=ans;
			}
			ans=0;
		}
		return;
	}
	for(int i=1; i<=3; i++)
	{
		cnt[i]++;
		b[pos]=a[pos][i];
		dfs(pos+1);
		cnt[i]--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int tot=0;
		int b1=1,b2=1,b3=1;
		cin >> n;
		for(int i=1; i<=n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if(a[i][2]!=0)
			{
				b2=0;
			}
			if(a[i][3]!=0)
			{
				b3=0;
			}
		}
		if(b2==1&&b3==1)
		{
			for(int i=1; i<=n; i++)
			{
				c[i]=a[i][1];
			}
			sort(c+1,c+1+n,cmp);
			for(int i=1; i<=n/2; i++)
			{
				tot+=c[i];
			}
			cout << tot << endl;
		}
		else
		{
			dfs(1);
			cout << maxn << endl;
			ans=0,maxn=0;
			cnt[1]=0;
			cnt[2]=0;
			cnt[3]=0;
		}

	}
	return 0;
}
