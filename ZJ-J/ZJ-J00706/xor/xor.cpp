#include <bits/stdc++.h>
using namespace std;
int n , k , a[1000001] , cnt = 0;
vector <int> b , c;
bool yh( int x ){
	for ( int i = 0; i < b.size(); i++ ){
		int sum = 0;
		char q , p;
		string s = "";
		while ( x != 0 || b[i] != 0 ){
			q = char(x % 2 + '0');
			x /= 2;
			p = char(b[i] % 2 + '0');
			b[i] /= 2;
			if ( q != p )	s = '1' + s;
			else	s = '0' + s;
		}for ( int i = s.size()-1; i >= 0; i-- ){
			if ( s[i] == '1' )	sum += pow(2 , i);
		}if ( sum == k ){
			return 1;
		}else if ( sum != 0 ){
			c.push_back(sum);
		}
	}
	return 0;
}
int main(){
	freopen("xor.in" , "r" , stdin );
	freopen("xor.out" , "w" , stdout );
	cin >> n >> k;
	for ( int i = 1; i <= n; i++ )	cin >> a[i];
	for ( int i = 1; i <= n; i++ ){
		if ( a[i] == k ){
			cnt++;
			b.clear();
			c.clear();
		}	
		else{
			if ( yh(a[i]) ){
				cnt++;
				b.clear();
				c.clear();
			}	
			else if ( !yh(a[i]) ){
				b.clear();
				b.push_back(a[i]);
				for ( int j = 0; j < c.size(); j++ ){
					b.push_back(c[j]);
				}
				c.clear();
			}	
		}
	}
	cout << cnt << endl;
	return 0;
}
