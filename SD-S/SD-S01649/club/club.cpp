#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 10;

int n,a[N][4],cnt[3],t[N];
ll ans;
priority_queue<int,vector<int>,greater<int> >q;

void upd(int k)
{
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++)
		if(t[i]==k)
			q.push(a[i][k]-max(a[i][(k+1)%3],a[i][(k+2)%3]));
	while(cnt[k]>n/2)
		ans-=q.top(),q.pop(),cnt[k]--;
	return ;
}

void solve()
{
	cin>>n;ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if(a[i][0]>=max(a[i][1],a[i][2]))
			cnt[0]++,ans+=a[i][0],t[i]=0;
		else if(a[i][1]>=max(a[i][0],a[i][2]))
			cnt[1]++,ans+=a[i][1],t[i]=1;
		else cnt[2]++,ans+=a[i][2],t[i]=2;
	}
	if(cnt[0]>n/2) upd(0);
	if(cnt[1]>n/2) upd(1);
	if(cnt[2]>n/2) upd(2);
	cout<<ans<<"\n";
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--) solve();
	return 0;
}
