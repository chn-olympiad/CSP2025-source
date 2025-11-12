#include <bits/stdc++.h> 
using namespace std;
const int N=1e5+10;
int n,ans,a[N][5],b[N],cnt[5];
void solve()
{
	cin>>n;
	cnt[1]=cnt[2]=cnt[3]=0;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int z=max(max(a[i][1],a[i][2]),a[i][3]);
		ans+=z;
		if(a[i][1]==z)cnt[1]++;
		else if(a[i][2]==z)cnt[2]++;
		else if(a[i][3]==z)cnt[3]++;
	}
	if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
	{
		cout<<ans<<'\n';
		return;
	}
	ans=0;
	for(int j=1;j<=3;j++)
	{
		int res=0;
		for(int i=1;i<=n;i++)
		{
			res+=a[i][j];b[i]=0;
			for(int k=1;k<=3;k++)
				if(k!=j)b[i]=max(b[i],a[i][k]);
			b[i]-=a[i][j];//换掉后的差值 
		}
		sort(b+1,b+n+1);
		for(int i=n;i>n/2;i--)res+=b[i];
		ans=max(ans,res); 
	}
	cout<<ans<<'\n';
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}