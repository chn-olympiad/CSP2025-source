#include<bits/stdc++.h>
using namespace std;
int  n , m ;
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out" , "w" , stdout);
	cin >>n >> m;
	
	int x  , y , pm = 1;
	cin >>x ;
	for (int i =2;i <= n*m ; i ++){
		cin >>y ;
		if ( y >x )	pm ++ ;
	}	
	
	if ( pm%n == 0 ) {
		int a = pm/n;
		if (a%2 == 1) {//若奇数，则上至下
			cout <<a <<" " << n ;
		}
		
		else if(a%2 == 0){//若偶数则下至上
			cout <<a <<" " << 1 ;
		}
	}
	else if (pm%n != 0) {
		int a = pm/n+1 ;
		
		if (a%2 == 1) {//若奇数，则上至下
			cout << a <<" " << ( pm-n*(a-1)  )  ;
		}
		else if(a%2 == 0){//若偶数则下至上
			cout << a<<" " << n- ( pm-n*(a-1)  ) +1 ;
		}
	}
	
	return 0;
}