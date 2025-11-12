#include<bits/stdc++.h>
using namespace std;

int n , m , a1;
int a[105] , d;

bool cmp( int x , int y ){
	return x > y;
}

int main(){
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for( int i = 1 ; i <= n * m ; i++ ){
		cin >> a[i];
		if( i == 1 )a1 = a[i];
	}
	sort(a+1,a+(n*m)+1,cmp);
	for( int i = 1 ; i <= n * m ; i++ )if( a[i] == a1 ){
		d = i;
		break;
	}
	if( d % n != 0 )cout << (d/n) + 1;
	else cout << d / n;
	cout << ' ';
	if( d / n % 2 == 0 )cout << d - d / n * n;
	else cout << n - (d - (d / n * n)) + 1;
	cout << endl << d << endl;
	for( int i = 1 ; i <= n * m ; i++ )cout << a[i] << ' ';

	return 0;
}