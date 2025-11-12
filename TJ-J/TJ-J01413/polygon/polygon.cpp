#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
想法：
1.输入木条数量和每一根木条的长度 
2.用递归枚举每一根木条  要/不要
3.当所有木条都选择完毕后，判断一下是否合格。
4.如果合格，统计下来 

合格条件：
所有选取的木棍长度总和-最长的 再和最长的边进行比较 
*/
ll n , a[100005] , d[100005] , sum;
bool check(){
	int num = 0 , maxx = 0 ;
	for(int i = 1 ; i <= n ; i ++){
		if(d[i] == 1){
			num += a[i] ;
			maxx = max(maxx , a[i]) ;
		}
	}
	if(num - maxx > maxx) return true ;
	else return false ;
}
void dg(int x){
	if(x == n + 1){
		if(check()) sum ++ ;
		return ;
	}else{
		for(d[x] = 0 ; d[x] <= 1 ; d[x] ++){
			dg(x + 1) ;
		}
	}
}
int main(){
	freopen("polygon.in" , "r" , stdin) ;
	freopen("polygon.out" , "w" , stdout) ;
	cin >> n ;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i] ;
	dg(1) ;
	cout << sum ;
	return 0;
}
