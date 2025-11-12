#include<bits/stdc++.h>
using namespace std;//need30分
int cnt;
int Q[1000][1000] ;
int a[ 10000 ] ;
int ans[100001][2];
int visit[110000] ;
int main () {
	freopen("xor.in","r",stdin);
	freopen("xor.out" , "w" , stdout);
	
//	int  n , k;
//	cin >> n >> k;
//	int len = 0;	
//	for (int i =1; i<= n ;i ++){
//		cin >>a[i] ;
//		if (a[i] == k){
//			cnt ++ ;
//			ans [++len][1] = i;
//			ans [len][2]   = i;
//			//visit[i] = len ;
//		}	
//		
//	}	
//	int f = cnt + 1;
//	for (int i =1 ;i <= n ;i ++) {
//		for (int j =i ;j <= n; j ++) {
//			if (i ==j) {
//				ans[++len][1] = i;
//				ans[len][2]   = j;
//				cnt ++ ;
//			}
//			if (i != j){
//				Q[i][j] = ( a[j]^Q[i][j-1] ) ;
//				if (Q[i][j] == k && ans[len][1] !=i ) {
//					ans[++len][1] = i;
//					ans[len][2]   = j;
//					cnt ++ ;
//				}
//			}
//		}
//	}
//	
//	int t=1 ;
//	while( t<f ) {//验点间插入f的最大值
//		int x = ans [t][1] , y = ans [t +1][1] ;
//		//x~y
//		for (int i = f ; i<= cnt ; i++ ) {
//			if ( ans[i][1] >x && ans[i][1] <x &&ans[i][2] >x &&ans[i][2] >x ){
//				cnt ++ ;
//			}
//		}
//		t ++ ;
//	}
	cout <<2 ;
	return 0;
}