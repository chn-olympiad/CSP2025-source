#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII; 
typedef long long ll;
const int N=1e5;
int T;
int n;
struct node{
	int v[3];
	int mx,mid,mn;
	int d;
}a[N+5];
bool cmp(node a,node b){return a.v[a.mx]==b.v[b.mx]?a.d<b.d:a.v[a.mx]>b.v[b.mx];}
priority_queue<PII,vector<PII>,greater<PII> > q[3];
int cnt[3];
int temp;
ll ans=0;
void solve()
{
	cin>>n;
	cnt[0]=cnt[1]=cnt[2]=ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v[0]>>a[i].v[1]>>a[i].v[2];
		a[i].mx=0;
		if(a[i].v[0]<a[i].v[1]) a[i].mx=1;
		if(a[i].v[a[i].mx]<a[i].v[2]) a[i].mx=2;
		a[i].mn=0;
		if(a[i].v[0]>a[i].v[1]) a[i].mn=1;
		if(a[i].v[a[i].mn]>a[i].v[2]) a[i].mn=2;
		if(a[i].mx!=0&&a[i].mn!=0) a[i].mid=0;
		if(a[i].mx!=1&&a[i].mn!=1) a[i].mid=1;
		if(a[i].mx!=2&&a[i].mn!=2) a[i].mid=2;
		a[i].d=a[i].v[a[i].mx]-a[i].v[a[i].mid];
		//cout<<a[i].mx<<" "<<a[i].mid<<" "<<a[i].mn<<"\n";
	}
	stable_sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(cnt[a[i].mx]==n/2)
		{
			if(q[a[i].mx].top().first>a[i].d)
			{
				cnt[a[i].mid]++;
				q[a[i].mid].push({a[i].d,i});
			}
			else
			{
				temp=q[a[i].mx].top().second;
				q[a[i].mx].pop();
				q[a[i].mx].push({a[i].d,i});
				cnt[a[temp].mid]++;
				q[a[temp].mid].push({a[temp].d,temp});
			}
		}
		else
		{
			cnt[a[i].mx]++;
			q[a[i].mx].push({a[i].d,i});
		}
	}
	for(int k=0;k<=2;k++)
	{
		while(!q[k].empty())
		{
			temp=q[k].top().second;q[k].pop();
			ans=ans+a[temp].v[k];
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)solve();
	return 0;
}
