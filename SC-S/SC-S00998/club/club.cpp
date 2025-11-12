#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define lc (u<<1)
#define rc (u<<1|1)
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define fst first
#define sed second
#define Min(a,b) ((a)>(b)?(a)=(b);1)
#define Max(a,b) ((a)<(b)?(a)=(b);1)
using namespace std;
const int N=1e5+10;
bool MS;int uesd,id;
int n; 
pii a[N][3];
struct vl
{
	int from,val,next;//来自哪个i，减少的权值是多少，下一个元素是第几大的 
	bool operator<(const vl&b)const
	{
		if(val!=b.val)
		return val<b.val;
		return from<b.from;
	}
};
void solve()
{
	cin>>n;
	int ans=0;
	set<vl>q[3];
	rep(i,1,n)
	{
		rep(j,0,2)
		cin>>a[i][j].fst,a[i][j].sed=j;
		sort(a[i],a[i]+3);
		reverse(a[i],a[i]+3);
		ans+=a[i][0].fst;
		q[a[i][0].sed].insert(vl{i,a[i][0].fst-a[i][1].fst,1});
		if(q[a[i][0].sed].size()>n/2)
		{
			int u=q[a[i][0].sed].begin()->from;
			int nxt=q[a[i][0].sed].begin()->next;
			ans-=q[a[i][0].sed].begin()->val;
			q[a[i][0].sed].erase(q[a[i][0].sed].begin()); 
			if(nxt!=3)
			{
//				ans+=a[u][nxt].fst;//注意这里就不用加了 
				if(nxt==2)
				q[a[u][nxt].sed].insert(vl{u,a[u][2].fst,3});
				else 
				q[a[u][nxt].sed].insert(vl{u,a[u][1].fst-a[u][2].fst,2});
			}
		}
	}
	cout<<ans<<'\n';
}
bool MT;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	cin>>T;
	while(T--)
	solve();
	cerr<<"Memory:"<<(&MS-&MT)/1048576.0<<"MB Time:"<<clock()<<"ms\n";
}
/*
问题是三个序列选不交的值，使得不存在一个序列选择了超过一半的数。

反悔贪心

每个决策点优先加入最大值，满了之后考虑加入当前元素然后弹掉代价最小。

特殊情况是两个序列都选择了n/2个元素且n为奇数

欸不过n是偶数欸，那么任意选择一个替换都是对的了



注意边界，极限时空。linux测，freopen，提交

人家的都csp了，你得让让人家 
*/