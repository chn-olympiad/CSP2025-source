#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define c(x) cout<<"#x"<<" = "<<x<<endl;
using namespace std;
const int N=1e5+10;
int a[N][10];
int b[N];
int t,n;
int ans=0;
map<int,int> mp;
void check(int x)
{
	if(mp[x]>n/2)
	{
		vector<PII> vec;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==x) vec.push_back({a[i][x]-max(a[i][(x+1)%3],a[i][(x+2)%3]),i});
		}
		sort(vec.begin(),vec.end());
		for(int i=0;i<mp[x]-n/2;i++)
		{
			ans-=vec[i].first;
		}
	}
}
void solve()
{
	mp.clear();
	scanf("%lld",&n);
	ans=0;
	for(int i=1;i<=n;i++)	b[i]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		int maxx=max(a[i][0],max(a[i][1],a[i][2]));
		ans+=maxx;
		if(maxx==a[i][0]) mp[0]++,b[i]=0;
		else if(maxx==a[i][1]) mp[1]++,b[i]=1;
		else mp[2]++,b[i]=2; 
	}
	check(0);
	check(1);
	check(2);
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--) solve();
	return 0;
}


