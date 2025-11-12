#include <bits/stdc++.h>
using namespace std;
int s[15][15], n, m, a[1000];
bool cmp( int x, int y ){
	return x > y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for( int i = 1; i <= n * m; i++ ){
    	cin >> a[i];
	}
	long long t = a[1], x = 1, y = 1;
	sort(a+1, a+1+(n*m), cmp);
	bool f = false;
	for( int i = 1; i <= n*m; i++ ){
		if( a[i] == t ){
			cout << y << ' ' << x;
			break;
		}
		if( x != n && !f ){
			x++;
		}
		else if( x != 1 && f ){
			x--;
		}
		else{
			y++;
			if( f ){
				f = false;
			}
			else{
				f = true;
			}
		}
	}
    return 0;
}
