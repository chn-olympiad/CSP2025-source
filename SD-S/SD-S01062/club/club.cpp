#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;

const int N = 1e5 + 10;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}

int T, n, tot1, tot2, tot3;
int a[N][4];
ll ans;
vector<int> c[5];
void clear(){
	tot1 = 0;tot2 = 0;tot3 = 0;ans = 0;
	while( !c[0].empty())c[0].pop_back();
	while( !c[1].empty())c[1].pop_back();
	while( !c[2].empty())c[2].pop_back();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	T = read();
	while( T-- ){
		clear();
		n = read();
		for( int i = 1 ; i <= n ; ++i ){
			a[i][0] = read();a[i][1] = read();a[i][2] = read();
			if( a[i][0] >= a[i][1] && a[i][0] >= a[i][2] )ans += a[i][0], c[0].pb(min(a[i][0]-a[i][1],a[i][0]-a[i][2])), tot1++;
			else if( a[i][1] >= a[i][0] && a[i][1] >= a[i][2] )ans += a[i][1], c[1].pb(min(a[i][1]-a[i][2],a[i][1]-a[i][0])), tot2++;
			else if( a[i][2] >= a[i][1] && a[i][2] >= a[i][0] )ans += a[i][2], c[2].pb(min(a[i][2]-a[i][0],a[i][2]-a[i][1])), tot3++;
		}
		n >>= 1;
		if( tot1 <= n && tot2 <= n && tot3 <= n )cout << ans << "\n";
		else{
			if( tot1 > n ){
				sort(c[0].begin(),c[0].end());
				for( int i = 0 ; i < tot1 ; ++i ){
					if( tot1 - i > n )ans -= c[0][i];
					else break;
				}
				cout << ans << "\n";
			}
			if( tot2 > n ){
				sort(c[1].begin(),c[1].end());
				for( int i = 0 ; i < tot2 ; ++i ){
					if( tot2 - i > n )ans -= c[1][i];
					else break;
				}
				cout << ans << "\n";
			}
			if( tot3 > n ){
				sort(c[2].begin(),c[2].end());
				for( int i = 0 ; i < tot3 ; ++i ){
					if( tot3 - i > n )ans -= c[2][i];
					else break;
				}
				cout << ans << "\n";
			}
		}
		
	}
	return 0;
}

