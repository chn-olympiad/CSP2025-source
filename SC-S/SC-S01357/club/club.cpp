/*
第一眼觉得这是一个反悔贪心的板子题
思考了下好像确实是反悔贪心板子题

写了下，觉得可以先口胡一下思路
记录每组最大的值及其编号，O(n)扫过去看合法性
还易得我们要么选最大的，要么就选次大的，不会出现选第三大的数的情况

转化问题为要么选最大，要么选次大的n个数满足条件
首先选择数直到存在一组数可能

md返回贪心写错了。得条一会了
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define QWQ return 0;
#define pii pair< int,int >
#define val first
#define idx second

const int N=1e5+10;

pii read[4];

struct cmp
{
	int big, nbig, idx;
	
	bool operator< ( const cmp &a )const
	{
		return big-nbig > a.big-a.nbig;
		//tmd我是SB，a.nbig写成nbig调了1h
	}
};

struct node
{
	pii a, b;
}mp[N];

void sovel()
{
	int n;
	cin>>n;
	for( int i=1;i<=n;i++ )
	{
		for( int j=1;j<=3;j++  ) cin>>read[j].val, read[j].idx=j;
		sort( read+1,read+3+1,greater< pii >() );
		mp[i].a=read[1], mp[i].b=read[2];
	}
	priority_queue< cmp > pq[4];
	for( int i=1;i<=n;i++ )
	{
		auto [val,group]=mp[i].a;
		if( n/2 == pq[group].size() )
		{
			auto [va,nva,id]=pq[group].top();
			if( val > va-nva )
			{
				pq[group].pop();
				pq[group].push( { val,mp[i].b.val,i } );
				pq[mp[id].b.idx].push( { mp[id].b.val,-10000000,id } );
			}
			else
			{
				pq[mp[i].b.idx].push( { mp[i].b.val,-10000000,i } );
			}	
		}
		else pq[group].push( { val,mp[i].b.val,i } );
	}
	int ans=0;
	for( int i=1;i<=3;i++ )
		while( !pq[i].empty() )
			ans+=pq[i].top().big, pq[i].pop();
	cout<<ans<<"\n";
}

int main()
{
	freopen( "club.in","r",stdin );
	freopen( "club.out","w",stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr ), cout.tie( nullptr );
	int t;
	for( cin>>t;t;t-- ) sovel();
	QWQ
}