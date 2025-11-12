//李中易 SN-S00316 西安辅轮中学
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100010;

struct str  { int ren,num,cha; };

int t,n,a[maxn][5],flag[maxn],sum[2];
ll ans;
vector<str>v;

priority_queue<int>q[2];

bool cmp(str x,str y)  { return x.num>y.num; }

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;ans=0;
		for(int i=1;i<=n;i++)  for(int j=1;j<=3;j++)  cin>>a[i][j];
		v.clear();
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][1];
			a[i][2]-=a[i][1];a[i][3]-=a[i][1];
			if(a[i][2]>=a[i][3])  v.push_back({0,a[i][2],a[i][3]-a[i][2]});
			if(a[i][2]<a[i][3])  v.push_back({1,a[i][3],a[i][2]-a[i][3]});
		}
		sort(v.begin(),v.end(),cmp);
		sum[1]=sum[0]=0;
		for(int i=0;i<n;i++)
		{
			int add=v[i].num,now=v[i].ren;
			q[now].push(v[i].cha);
			sum[now]++;
			if(sum[now]>(n/2))
			{
				add+=q[now].top();sum[now]--;
				if(add<0)  continue;
				q[now].pop();sum[now^1]++;
			}
			if(i>=(n/2)&&add<0)  continue;
			ans+=add;
		}
		while(!q[0].empty())  q[0].pop();  while(!q[1].empty())  q[1].pop();
		cout<<ans<<"\n";
	}
	return 0;
} 
