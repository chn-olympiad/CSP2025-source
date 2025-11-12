/*
wow尽然是美妙的区间DP吗？
或者bitset状压一下进行DP

不会写，8分也是分，直接开始暴力
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define QWQ return 0;
#define pii pair< int,int >

const int N=5e2+10;

int c[N];

int main()
{
	freopen( "employ.in","r",stdin );
	freopen( "employ.out","w",stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr ), cout.tie( nullptr );
	int n, m;
	cin>>n>>m;
	string level;
	cin>>level;
	level=" "+level;
	for( int i=1;i<=n;i++ ) cin>>c[i];
	vector< int > vec( n+1 );
	int ans=0;
	for( int i=0;i<=n;i++ ) vec[i]=i;
	do
	{
		int no=0;
		for( int i=1;i<=n;i++ )
			if( level[i] == '0' || no >= c[vec[i]] )
				no++;
		ans+=( no <= n-m );
	}while( next_permutation( vec.begin()+1,vec.end() ) );
	cout<<ans;
	QWQ
}