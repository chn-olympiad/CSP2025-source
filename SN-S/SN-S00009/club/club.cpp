#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][3],mxn[100005],sd[100005];
long long ans=0;
int cnt[3];
int h[100005],h1;
int w(int aa,int bb,int cc)
{
	if(aa>=bb && aa>=cc) return 0;
	if(bb>=aa && bb>=cc) return 1;
	if(cc>=aa && cc>=bb) return 2;
}
void solve()
{
	ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	h1=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		mxn[i]=w(a[i][0],a[i][1],a[i][2]);
		cnt[mxn[i]]++;
		ans+=a[i][mxn[i]];
		if(mxn[i]==0) 
		{
			if(a[i][1]>=a[i][2]) sd[i]=1;
			else sd[i]=2;
		}
		else if(mxn[i]==1)
		{
			if(a[i][0]>=a[i][2]) sd[i]=0;
			else sd[i]=2;
		}
		else
		{
			if(a[i][0]>=a[i][1]) sd[i]=0;
			else sd[i]=1;
		}
	}
	int hcnt=0;
	if(cnt[0]>n/2)
	{
		hcnt=cnt[0]-n/2;
		for(int i=1;i<=n;i++)
		{
			if(mxn[i]==0) h[++h1]=a[i][mxn[i]]-a[i][sd[i]];
		}
	}
	else if(cnt[1]>n/2)
	{
		hcnt=cnt[1]-n/2;
		for(int i=1;i<=n;i++)
		{
			if(mxn[i]==1) h[++h1]=a[i][mxn[i]]-a[i][sd[i]];
		}
	}
	else if(cnt[2]>n/2)
	{
		hcnt=cnt[2]-n/2;
		for(int i=1;i<=n;i++)
		{
			if(mxn[i]==2) h[++h1]=a[i][mxn[i]]-a[i][sd[i]];
		}
	}
	else
	{
		cout<<ans<<endl;
		return;
	}
	sort(h+1,h+1+h1);
	for(int i=1;i<=hcnt;i++)
	{
		ans-=h[i];
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
