#include<bits/stdc++.h>
using namespace std;
int t , n , x , num ;
int A[4] = { 0 , 0 , 0 , 0 } ;

struct Sr {
	int num ;
	int a , b , c ;
} Stu[100005] ;

bool cmp1 ( Sr s1 , Sr s2 ) {
	if ( s1.a == s2.a ) {
		if ( s1.b == s2.b ) {
			return s1.c < s2.c ;
		}
		return s1.b < s2.b ;
	}
	return s1.a > s2.a ;
}

bool cmp2 ( Sr s1 , Sr s2 ) {
	if ( s1.b == s2.b ) {
		return s1.c < s2.c ;
	}
	return s1.b > s2.b ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t ;
	while ( t-- ) {
		cin >> n ;
		num = 0 ;
		memset ( A , 0 , sizeof ( A ) ) ;
		x = n / 2 ;
		for ( int i = 0 ; i < n ; i++ ) {
			Stu[i].num = i ;
			cin >> Stu[i].a >> Stu[i].b >> Stu[i].c ;
		}
		sort ( Stu , Stu + n , cmp1 ) ;
		while ( A[0] + 1 <= x && Stu[A[0]].a >= Stu[A[0]].b && Stu[A[0]].a >= Stu[A[0]].c ) {
			num += Stu[A[0]].a ;
			A[0]++ ;
		}
		sort ( Stu + A[0] , Stu + n , cmp2 ) ;
		while ( A[1] + 1 <= x && Stu[A[0]+A[1]].b >= Stu[A[0]+A[1]].c ) {
			num += Stu[A[0]+A[1]].b ;
			A[1]++ ;
		}
		for ( int i = A[0] + A[1] ; i < n && i + 1 <= x ; i++ ) {
			num += Stu[i].c ;
			A[2]++ ;
		}
		cout << num << endl ;
		cout << A[0] << ' ' << A[1] << ' ' << A[2] ;
	}
	return 0;
}

