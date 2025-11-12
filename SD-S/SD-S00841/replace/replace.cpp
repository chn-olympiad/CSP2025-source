#include<bits/stdc++.h>
using namespace std;

#define N 200010
#define M 5000010
#define il inline
#define ull unsigned long long
const ull bas = 79113;

bool tes1;

int n, Q, totid;
ull mi[M], hs1[M], hs2[M];
char s1[M], s2[M];
struct node {
	int l, r; ull hs;
};
unordered_map <ull, int> mp;
vector <node> v[N]; 

struct sub1 {
	
	il void init()
	{
		mi[0] = 1;
		for( int i = 1; i < N; i ++ ) mi[i] = mi[i - 1] * bas;
	}
	
	il void sol()
	{
		init(); ull hs;
		for( int i = 1, l, r, len; i <= n; i ++ )
		{
			cin >> (s1 + 1) >> (s2 + 1); len = strlen( s1 + 1 );
			l = 1, r = len;
			while( l <= len && s1[l] == s2[l] ) l ++;
			while( r >= 1 && s1[r] == s2[r] ) r --;
			if( r == 0 ) continue;
			
			for( int j = 1; j <= len; j ++ )
			{
				hs1[j] = hs1[j - 1] * bas + (ull)s1[j];
				hs2[j] = hs2[j - 1] * bas + (ull)s2[j];
			}
			
			hs = (hs1[r] - hs1[l - 1] * mi[r - l + 1]) * mi[r - l + 1] + (hs2[r] - hs2[l - 1] * mi[r - l + 1]);
			if( mp.find( hs ) == mp.end() ) mp[hs] = ++totid;
			v[mp[hs]].push_back( (node){l - 1, len - r, hs1[len]} );
			
//			cout << i << " : " << l << " " << r << " " << hs << " " << (hs1[r] - hs1[l - 1] * mi[r - l + 1]) << " " << (hs2[r] - hs2[l - 1] * mi[r - l + 1]) << endl;
		}
		
		for( int i = 1, l, r, len, id, ll, rr, res; i <= Q; i ++ )
		{
			cin >> (s1 + 1) >> (s2 + 1); len = strlen( s1 + 1 );
			l = 1, r = len; res = 0;
			while( l <= len && s1[l] == s2[l] ) l ++;
			while( r >= 1 && s1[r] == s2[r] ) r --;
			
			for( int j = 1; j <= len; j ++ )
			{
				hs1[j] = hs1[j - 1] * bas + (ull)s1[j];
				hs2[j] = hs2[j - 1] * bas + (ull)s2[j];
			}
			hs = (hs1[r] - hs1[l - 1] * mi[r - l + 1]) * mi[r - l + 1] + (hs2[r] - hs2[l - 1] * mi[r - l + 1]);
			if( mp.find( hs ) != mp.end() )
			{
				id = mp[hs], res = 0;
				for( auto nw : v[id] )
				{
					ll = l - nw.l; rr = r + nw.r;
					if( ll >= 1 && rr <= len && hs1[rr] - hs1[ll - 1] * mi[rr - ll + 1] == nw.hs ) res ++;
				}
			}
//			cout << i << " : " << l << " " << r << " " << hs << " " << (hs1[r] - hs1[l - 1] * mi[r - l + 1]) << " " << (hs2[r] - hs2[l - 1] * mi[r - l + 1]) << endl;
			cout << res << '\n';
		}
	}
} sub1;

struct sub2 {
	#define lowbit(p) ((-(p))&(p))
	
	int rtl[N], rtr[N], totl, totr, nxtl[M][26], nxtr[M][26], pos[N], posq[N], dfn[M], tim, siz[M], son[M], top[M], fa[M], c[M], res[M];
	vector <int> poi[M], ql[M], e[M];
	
	il void init()
	{
		mi[0] = 1;
		for( int i = 1; i < N; i ++ ) mi[i] = mi[i - 1] * bas;
	}
	
	il void insert_l( int id, int l, int j )
	{
		int p = rtl[id];
		for( int i = l; i >= 1; i -- )
		{
			int c = s1[i] - 'a';
			if( nxtl[p][c] == 0 ) nxtl[p][c] = ++totl;
			p = nxtl[p][c];
		}
		poi[p].push_back( j );
	}
	
	il void insert_r( int id, int r, int len, int j )
	{
		int p = rtr[id];
		for( int i = r; i <= len; i ++ )
		{
			int c = s1[i] - 'a';
			if( nxtr[p][c] == 0 ) nxtr[p][c] = ++totr;
			p = nxtr[p][c];
		}
		pos[j] = p;
	}
	
	il void insert_ql( int id, int l, int j )
	{
		int p = rtl[id];
		for( int i = l; i >= 1; i -- )
		{
			int c = s1[i] - 'a';
			if( nxtl[p][c] == 0 ) break;
			p = nxtl[p][c];
		}
		ql[p].push_back( j );
	}
	
	il void insert_qr( int id, int r, int len, int j )
	{
		int p = rtr[id];
		for( int i = r; i <= len; i ++ )
		{
			int c = s1[i] - 'a';
			if( nxtr[p][c] == 0 ) break;
			p = nxtr[p][c];
		}
		posq[j] = p;
	}
	
	void dfs1( int x, int par )
	{
		fa[x] = par; siz[x] = 1;
		for( int i = 0, v; i <= 25; i ++ )
		{
			if( nxtr[x][i] == 0 ) continue;
			v = nxtr[x][i]; e[x].push_back( v );
			dfs1( v, x );
			siz[x] += siz[v];
			if( siz[v] > siz[son[x]] ) son[x] = v;
		}
	}
	
	void dfs2( int x, int tp )
	{
		top[x] = tp; dfn[x] = ++tim;
		if( son[x] ) dfs2( son[x], tp );
		for( int v : e[x] )
			if( v != son[x] ) dfs2( v, v );
	}
	
	il void change( int p, int v )
	{
		for( ; p <= tim; p += lowbit(p) ) c[p] += v;
	}
	
	il int ask_c( int p )
	{
		int ans = 0;
		for( ; p; p -= lowbit(p) ) ans += c[p];
		return ans;
	}
	
	il int ask( int l, int r ) { return ask_c( r ) - ask_c( l - 1 ); }
	
	il int query( int x )
	{
		int ans = 0;
		while( x )
		{
			ans += ask( dfn[top[x]], dfn[x] );
			x = fa[top[x]];
		}
		return ans;
	}
	
	void dfs3( int x )
	{
		if( !x ) return ;
		for( int i : poi[x] ) change( dfn[pos[i]], 1 );
		for( int i : ql[x] ) res[i] = query( posq[i] );
		for( int i = 0; i <= 25; i ++ )
			if( nxtl[x][i] ) dfs3( nxtl[x][i] );
		for( int i : poi[x] ) change( dfn[pos[i]], -1 );
	}
	
	il void readin()
	{
		ull hs;
		for( int i = 1, l, r, len; i <= n; i ++ )
		{
			cin >> (s1 + 1) >> (s2 + 1); len = strlen( s1 + 1 );
			l = 1, r = len;
			while( l <= len && s1[l] == s2[l] ) l ++;
			while( r >= 1 && s1[r] == s2[r] ) r --;
			if( r == 0 ) continue;
			
			for( int j = 1; j <= len; j ++ )
			{
				hs1[j] = hs1[j - 1] * bas + (ull)s1[j];
				hs2[j] = hs2[j - 1] * bas + (ull)s2[j];
			}
			
			hs = (hs1[r] - hs1[l - 1] * mi[r - l + 1]) * mi[r - l + 1] + (hs2[r] - hs2[l - 1] * mi[r - l + 1]);
			if( mp.find( hs ) == mp.end() ) mp[hs] = ++totid, rtl[totid] = ++totl, rtr[totid] = ++totr;
			insert_l( mp[hs], l - 1, i ); insert_r( mp[hs], r + 1, len, i );
			
//			cout << i << " : " << l << " " << r << " " << hs << " " << (hs1[r] - hs1[l - 1] * mi[r - l + 1]) << " " << (hs2[r] - hs2[l - 1] * mi[r - l + 1]) << endl;
		}
		
		for( int i = 1, l, r, len; i <= Q; i ++ )
		{
			cin >> (s1 + 1) >> (s2 + 1); len = strlen( s1 + 1 );
			l = 1, r = len;
			while( l <= len && s1[l] == s2[l] ) l ++;
			while( r >= 1 && s1[r] == s2[r] ) r --;
			
			for( int j = 1; j <= len; j ++ )
			{
				hs1[j] = hs1[j - 1] * bas + (ull)s1[j];
				hs2[j] = hs2[j - 1] * bas + (ull)s2[j];
			}
			hs = (hs1[r] - hs1[l - 1] * mi[r - l + 1]) * mi[r - l + 1] + (hs2[r] - hs2[l - 1] * mi[r - l + 1]);
			if( mp.find( hs ) != mp.end() )
				insert_ql( mp[hs], l - 1, i ), insert_qr( mp[hs], r + 1, len, i );
//			cout << i << " : " << l << " " << r << " " << hs << " " << (hs1[r] - hs1[l - 1] * mi[r - l + 1]) << " " << (hs2[r] - hs2[l - 1] * mi[r - l + 1]) << endl;
		}
	}
	
	il void sol()
	{
		init(); readin();
		for( int i = 1; i <= totid; i ++ )
			dfs1( rtr[i], 0 ), dfs2( rtr[i], rtr[i] );
		for( int i = 1; i <= totid; i ++ )
			dfs3( rtl[i] );
		for( int i = 1; i <= Q; i ++ ) cout << res[i] << '\n';
	}
} sub2;

bool tes2;

int main()
{
//	cout << (&tes1 - &tes2) / 1024 / 1024 << endl;
	ios::sync_with_stdio( 0 );
	cin.tie( 0 );
	freopen( "replace.in", "r", stdin );
	freopen( "replace.out", "w", stdout );
	cin >> n >> Q;
	if( n <= 10000 && Q <= 10000 ) sub1.sol();
	else sub2.sol();
	return 0;
}
