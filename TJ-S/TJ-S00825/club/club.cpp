//你应该放下一切，不再为你的过去懊恼 
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005][5];
int cnt[5],b[100005],cur;
int mian()
{
	//多测清空 
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			cin>>a[i][j];
	int ans=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++)
	{
		int now=1;
		for(int j=2;j<=3;j++)
			if(a[i][j]>a[i][now])
				now=j;
		ans+=a[i][now];
		cnt[now]++;
	}
	int id=-1;
	for(int i=1;i<=3;i++)
		if(cnt[i]*2>n)
			id=i;
	if(id==-1)
	{
		cout<<ans<<"\n";
		return 0;
	}
	cur=0;
	for(int i=1;i<=n;i++)
	{
		int now=1;
		for(int j=2;j<=3;j++)
			if(a[i][j]>a[i][now])
				now=j;
		if(now==id)
		{
			int k=0x3f3f3f3f;
			for(int j=1;j<=3;j++)
				if(j!=now)
					k=min(k,a[i][now]-a[i][j]);
			b[++cur]=k;
		}
	}
	sort(b+1,b+cur+1);
	for(int i=n/2+1;i<=cnt[id];i++)
		ans-=b[i-n/2];
	cout<<ans<<"\n";
	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
		mian();
	return 0;
}
