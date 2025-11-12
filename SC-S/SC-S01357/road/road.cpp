/*
电力修建？
超级源点最小生成树？
对于每个额外的村庄，如果他们的选择上的连边只有一条，则一定是为了联通而联通,记录直接减去额外答案即可

不是这样的QAQ

先在原图上跑最小生成树，再考虑换边吗？

感觉有点熟悉，再思考一下

不管怎么样，能解决这个C的点权的只有超级源点
对每个可升级的村庄连一条超级源点，然后延迟连边，当超级源点这条边加入时才连，并记录与它直接相关的边，答案加上c[i]*( 直接相关边>=1?1:0 )？

写一个暴力一点的方法看下可不可行
nmd暴力的方法好像时间上没问题
开凹

现在这个方法的问题在于存在后效性，可能会选择到比以前更优的解
思考如何处理这个问题

最后20min想了一个方法，如果设置一个中转点，额外点到它的距离是C，原点到它的距离是0x3f3f3f3f（不一定连上）
连接上后更新中转点到原点的距离即可
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define QWQ return 0;
#define pii pair< int,int >

const int N=2e4+10;

int fa[N];
int c[N], dre[N], Cnt[N];
bool vis[N];
vector< pii > rode[N];

int get( int x ){ return ( fa[x] == x ? x : fa[x]=get( fa[x] ) ); }
void merge( int x,int y ){ fa[get( x )]=get( y ); }

struct node
{
	int u, v, w;
	
	bool operator< ( const node &a )const
	{
		return w > a.w;
	}
};

signed main()
{
	freopen( "road.in","r",stdin );
	freopen( "road.out","w",stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr ), cout.tie( nullptr );
	int n, m, k;
	cin>>n>>m>>k;
	for( int i=1;i<=n+k+10;i++ ) fa[i]=i;
	priority_queue< node > pq; 
	for( int i=1, u, v, w;i<=m;++i )
	{
		cin>>u>>v>>w;
		pq.push( { u,v,w } );
	}
	for( int i=1;i<=k;++i )
	{
		cin>>c[i];
		for( int j=1, x;j<=n;++j )
			cin>>x, rode[n+i].push_back( { j,x } ), pq.push( { j,n+i,x+c[i] } );
	}
	int tmp=n;
	int cnt=1;
	ll ans=0;
	while( cnt < tmp )
	{
		auto [u,v,w]=pq.top();
		pq.pop();
		if( get( u ) == get( v ) ) continue;
		cnt++;
		merge( u,v );
		ans+=w;
		if( v > n ) ++Cnt[v];
		if( v > n && !vis[v] )
		{
			dre[v]=w;
			vis[v]=true;
			tmp++;
			for( auto [x,val]:rode[v] )
				pq.push( { x,v,val } );
		}
	}
	for( int i=k+1;i<=n+k;++i )
		if( Cnt[i] == 1 )
			ans-=dre[i];
	cout<<ans;
	QWQ
}