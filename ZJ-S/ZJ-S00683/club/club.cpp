#include<bits/stdc++.h>
using namespace std;
long long a[100005][5];
bool st[100005][5];
long long cnt[4];
vector<long long> v;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long T;
	cin>>T;
	while(T--)
	{
		memset(cnt,0,sizeof cnt);
		v.clear();
		memset(st,false,sizeof st);
		long long n;
		cin>>n;
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) cnt[1]++,st[i][1]=true,ans+=a[i][1];
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) cnt[2]++,st[i][2]=true,ans+=a[i][2];
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) cnt[3]++,st[i][3]=true,ans+=a[i][3];
		}
		long long p=0;
		if(cnt[1]>n/2) p=1;
		else if(cnt[2]>n/2) p=2;
		else if(cnt[3]>n/2) p=3;
		if(p==0) 
		{
			cout<<ans<<'\n';
			continue;
		}
		for(long long i=1;i<=n;i++)
		  if(st[i][p])
		  {
		  	if(p==1) v.push_back(a[i][1]-max(a[i][2],a[i][3]));
		  	else if(p==2) v.push_back(a[i][2]-max(a[i][1],a[i][3]));
		  	else if(p==3) v.push_back(a[i][3]-max(a[i][2],a[i][1]));
		  }
		sort(v.begin(),v.end());
		for(long long i=0;i<cnt[p]-n/2;i++) ans-=v[i];
		cout<<ans<<'\n';
	}
	return 0;
}
