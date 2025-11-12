#include<bits/stdc++.h>
using namespace std;

int t , n , ans;
struct node{
	int t1 , t2 , t3;
	bool f = false;
} a[100000];
int s1 , s2 , s3 , s;

bool cmp1( node x , node y ){
	return x.t1 > y.t1;
}

bool cmp2( node x , node y ){
	return x.t2 > y.t2;
}

bool cmp3( node x , node y ){
	return x.t3 > y.t3;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while( t-- ){
		ans = 0;
		cin >> n;
		for( int i = 1 ; i <= n ; i++ ){
			cin >> a[i].t1 >> a[i].t2 >> a[i].t3;
			a[i].f = false;
		}
		sort(a+1,a+n+1,cmp1);
		for( int i = 1 ; i <= n ; i++ ){
			if( a[i].f == false )cout << i << ':' << a[i].t1 << ' ' << a[i].t2 << ' ' << a[i].t3 << endl;
			//cout << i << ':' << a[i].t1 << ' ' << a[i].t2 << ' ' << a[i].t3 << endl;
		}
		for( int i = 1 ; i <= n ; i++ ){
			if( a[i].f == false){
				a[i].f = true;
				ans += a[i].t1;
				s1++;
				if( s1 >= n / 2 )break;
			}
		}
		sort(a+1,a+n+1,cmp2);
		for( int i = 1 ; i <= n ; i++ ){
			if( a[i].f == false )cout << i << ':' << a[i].t1 << ' ' << a[i].t2 << ' ' << a[i].t3 << endl;
			//cout << i << ':' << a[i].t1 << ' ' << a[i].t2 << ' ' << a[i].t3 << endl;
		}
		for( int i = 1 ; i <= n ; i++ ){
			if( a[i].f == false){
				a[i].f = true;
				ans += a[i].t2;
				s2++;
				if( s2 >= n / 2 )break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/