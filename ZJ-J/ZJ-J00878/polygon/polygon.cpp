#include<bits/stdc++.h>
using namespace std;//30~50
int k[ 10000 ] ;
int ans[10000] ;
int  n;
long long cnt;
void dfs( int deep ,int q ,int t , int Max,int ws  ) { // 深度 ， 前缀和 ， 上一个数字是第几个 ,数列最大值
//	cout <<deep <<" " << q <<"　"　<<t <<" "<< Max <<"　"　<<ws<<"\n";
	if ( deep == ws+1 ) {
		if (q > Max*2){
//			for (int i =1 ;i <= deep ; i ++){
//				cout <<ans[i] ;
//			}
			cnt ++ ;
		}
		//cout <<"\n " ;
		return ;
	}
	for (int i = t+1 ;i <= n ;i ++) {
		ans[deep] = k[i] ;
		dfs(deep +1 , q +k[i] , i , max(Max , k[i]) ,ws  ) ;
	}
	
	return ;
}
int main () {
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	int ws;
	cin >> n ;
	for (int i =1; i<= n ;i ++)	scanf("%d",&k[i]);
	//deep>=3 
	for (int i =3 ;i <= n ;i ++) {
		ws = i ;
		dfs( 1 , 0 , 0 , 0 ,ws ) ;
	}
	cout <<cnt%998244353 ;
	
	return 0;
}