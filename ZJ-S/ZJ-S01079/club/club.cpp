#include <bits/stdc++.h>
const int N=1e5+5;
using namespace std;
int a[N][4],id[N];
void solve()
{
	int n,cnt[4]={0,0,0,0},ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	id[i]=a[i][1]=a[i][2]=a[i][3]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		cin>>a[i][j];
		for(int j=1;j<=3;j++)
		{
			int flag=1;
			for(int k=1;k<=3;k++)
			if(j!=k)
			if(a[i][j]<a[i][k])flag=0;
			if(flag==1){id[i]=j;ans+=a[i][j];cnt[j]+=1;break;}
		}
	}
	for(int j=1;j<=3;j++)
	if(cnt[j]>n/2)
	{
		vector<int>v;
		for(int i=1;i<=n;i++)
		if(id[i]==j)
		{
			int temp=-1;
			for(int k=1;k<=3;k++)
			if(j!=k)
			temp=max(temp,a[i][k]);
			v.emplace_back(a[i][j]-temp);
		}
		sort(v.begin(),v.end());
		int jj=0;
		while(cnt[j]>n/2)
		{
			cnt[j]--;
			ans-=v[jj];jj++;
		}
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
}
