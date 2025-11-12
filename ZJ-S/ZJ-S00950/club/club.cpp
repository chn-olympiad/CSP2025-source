#include<bits/stdc++.h>
using namespace std;
int n ;
int k[100010][5];
int dp[100001][5] ;
//int d_p(  ) {
//	
//	dp[1][1].p = k[1][1] ;
//	dp[1][2].p = max (dp[1][1].p , k[1][2]) ;
//	dp[1][3].p = max (dp[1][2].p , k[1][3]) ;
//	
//	if (dp[ 1][1 ].p >dp[1 ][2 ].p && dp[1 ][1 ].p >dp[1 ][ 3].p)	dp[ 1 ][ 1 ].rs = 1 ;
//	if (dp[ 1][2 ].p >dp[1 ][1 ].p && dp[1 ][2 ].p >dp[1 ][ 3].p)	dp[ 1 ][ 2 ].rs = 1 ;
//	if (dp[ 1][3 ].p >dp[1 ][1 ].p && dp[1 ][3 ].p >dp[1 ][ 2].p)	dp[ 1 ][ 3 ].rs = 1 ;
//	for (int i =2 ;i <= n ;i ++) {
//		for (int j =1 ;j <= 3 ;j ++) {
//			if (i %2 == 1) {
//				int t =i/2+1 ;//renshu<t
//				if(  ) {
//					
//					
//				}
//			}
//			else {
//				int t = i/2 ;
//			}
//			cout <<dp[i][j] <<" ";
//		}
//		cout <<"\n" ;
//	}
//	
//	//
//	return  0;
//}
int ans = 0 , last=0 ;
int ps[100001] ;
void dfs(int deep , int a , int b , int c , int sum) {
	//cout <<deep <<" "<<a <<" "<<b<<" "<<c<<" "<<sum<<"\n";
	if (deep == n+1) {
		
		
//		for (int i =1 ;i <= n;i ++) {
//			cout <<ps[i] <<" " ;
//		}
//		cout <<"\n" ;
		ans =max (ans  , sum) ;
		return ;
	}
	if ( a >deep/2 || b>deep/2 || c>deep/2 )	return ;
	if (deep%2 == 1) {
		
		//if (a < deep /2+1  ) {
			ps[deep] = k[deep][1] ;
			dfs(deep +1 , a+1 , b , c , sum+k[deep][1]) ;
		//}
		//if (b < deep /2+1  ) {
			ps[deep] = k[deep][2] ;
			dfs(deep +1 , a ,b +1 ,c , sum +k[deep][2]) ;
		//}
		//if (c < deep /2+1  ) {
			ps[deep] = k[deep][3] ;
			dfs(deep +1 , a ,b , c+1 , sum +k[deep][3]) ;
		//}
	}
	if (deep%2 == 0) {
		//if (a < deep /2  ) {
			ps[deep] = k[deep][1] ;
			dfs(deep +1 , a+1 , b , c , sum+k[deep][1]) ;
		//}
		//if (b < deep /2  ) {
			ps[deep] = k[deep][2] ;
			dfs(deep +1 , a ,b +1 ,c , sum +k[deep][2]) ;
		//}//
		//if (c < deep /2  ) {
			ps[deep] = k[deep][3] ;
			dfs(deep +1 , a ,b , c+1 , sum +k[deep][3]) ;
		//}
	}
	
	return  ;
}
int main () {
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	int t ;
	cin >>t;
	for (int i =1; i<= t; i++) {
		cin >>n ;
		memset(ps , 0 , sizeof(ps)) ;
		ans = 0 , last = 0 ;
		for (int j =1;j <= n; j++)	cin >>k[j][1] >> k[j][2] >>k[j][3] ;
		//cout <<"\n\n";
		
		//number 1
		ps[1] = k[1][1] ;
		dfs( 2 ,  1,0,0  ,k[1][1] );
		last = ans ;
		///////////////////
		ps[1] = k[1][2] ;
		ans = 0;
		dfs( 2 ,  0,1,0  ,k[1][2] );
		last = max(last , ans) ;	
		///////////////////
		ps[1] = k[1][3];
		ans = 0;
		dfs( 2 ,  0,0,1  ,0);
		last = max (last , k[1][3] );
		///////////////////					
		cout <<last <<"\n" ;
		last = 0 ;
	}
	
	return 0;
}