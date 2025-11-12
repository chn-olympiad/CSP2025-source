#include<bits/stdc++.h>
using namespace std;

int n, m, tot, R;
int a[110], mp[110][110];

bool cmp(const int &a, const int &b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	tot = n * m;
	
	for ( int i = 1; i <= tot; i++ ) {
		cin >> a[i];
	}
	
	R = a[1];
	
	sort(a + 1, a + 1 + tot, cmp );
	
	int pos = find(a + 1, a + 1 + tot, R) - a;
	int lie = ( pos - 1 ) / n + 1 ;
	int hang;
	if ( lie & 1 ) {
		hang = ( ( pos - 1 ) % n ) + 1;
	} else {
		hang = n - ( ( pos - 1 ) % n );
	}
	cout << lie << ' ' << hang; 
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
