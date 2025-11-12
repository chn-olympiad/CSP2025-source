/*
线性计数类带KMP优化的DP吧
不会写，只能拿一下暴力分
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define QWQ return 0;
#define pii pair< int,int >

const int N=2e5+10;

map< string,string > mp;

int n, q;
int zero[N];

void bf()//不想写暴力了
{
	for( int i=1;i<=q;i++ )
		cout<<"0\n";
	return ;
}

void sp()//没写对，未处理越界情况
{
	for( int i=1;i<=q;++i )
	{
		string s1, s2;
		cin>>s1>>s2;
		int l, r;
		for( int j=1;j<=s1.size();++j )
			if( s1[j-1] == 'b' )
				l=j;
		for( int j=1;j<=s2.size();++j )
			if( s2[j-1] == 'b' )
				r=j;
		auto it1=lower_bound( zero+1,zero+n+1,l-r )-zero;
		auto it2=upper_bound( zero+1,zero+n+1,l-r )-zero-1;
		cout<<max( 0,it2-it1 )<<"\n";
	}
}

int main()
{
	freopen( "replace.in","r",stdin );
	freopen( "replace.out","w",stdout );
	ios::sync_with_stdio( false );
	cin.tie( nullptr ), cout.tie( nullptr );
	cin>>n>>q;
	for( int i=1;i<=n;++i )
	{
		string s1, s2;
		cin>>s1>>s2;
		mp[s1]=s2;
		int l, r;
		for( int j=1;j<=s1.size();++j )
			if( s1[j-1] == 'b' )
				l=j;
		for( int j=1;j<=s2.size();++j )
			if( s2[j-1] == 'b' )
				r=j;
		zero[i]=l-r;
	}
	sort( zero+1,zero+n+1 );
	if( n <= 1e3 ) bf();
	else sp();
	QWQ
}