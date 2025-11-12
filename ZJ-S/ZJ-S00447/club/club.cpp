#include<bits/stdc++.h>
using namespace std;
int n,a[5][100005],T,cana=1,canb=1;
long long ans;
vector<int>w1,w2;
int cnta,cntb,cntc;
void dfs(int x,long long sum)
{
	if(x==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	if(cnta<n/2)
	{
		cnta++;
		dfs(x+1,sum+a[1][x]);
		cnta--;
	}
	if(cntb<n/2)
	{
		cntb++;
		dfs(x+1,sum+a[2][x]);
		cntb--;
	}
	if(cntc<n/2)
	{
		cntc++;
		dfs(x+1,sum+a[3][x]);
		cntc--;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		ans=0;
		cana=canb=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[3][i]!=0)cana=canb=0;
			if(a[2][i]!=0)cana=0;
		}
		if(cana)
		{
			sort(a[1]+1,a[1]+1+n,greater<int>());
			for(int i=1;i<=n/2;i++)ans+=a[1][i];
		}
		else if(canb)
		{
			w1.clear(),w2.clear();
			int cnt1=0,cnt2=0;
			for(int i=1;i<=n;i++)
			{
				if(a[1][i]>=a[2][i])cnt1++,w1.push_back(i);
				else cnt2++,w2.push_back(i);
			}
			if(cnt1>n/2)
			{
				sort(a[1]+1,a[1]+n+1,greater<int>());
				for(int i=1;i<=n/2;i++)ans+=a[1][i];
				for(int i=n/2+1;i<=cnt1;i++)ans+=a[2][i];
				for(int i=1;i<=cnt2;i++)ans+=a[2][w2[i-1]];
			}
			else
			{
				sort(a[2]+1,a[2]+n+1,greater<int>());
				for(int i=1;i<=n/2;i++)ans+=a[2][i];
				for(int i=n/2+1;i<=cnt2;i++)ans+=a[1][i];
				for(int i=1;i<=cnt1;i++)ans+=a[1][w1[i-1]];
			}
		}
		else if(n==2)
		{
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i!=j)ans=max(ans,1LL*(a[i][1]+a[j][2]));
				}
			}
		}
		else
		{
			cnta=cntb=cntc=0;
			dfs(1,0);
		}
		cout<<ans<<endl;
	}
	return 0;
}
