#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
想法：
1.输入n和每个人对于1,2,3这三个社团的满意度
2.通过递归来规定每个人的社团情况
3.当所有人的社团情况都规定好以后，把他们对应社团的满意程度加起来(在定社团的时候就用sum统计好了) 
4.把这个和与最大值比较 
*/
ll t , n , a[100005][5] , ans , d[100005] , tong[5];
void dg(ll x , ll sum){
	if(x == n + 1){
		ans = max(ans , sum) ;                       //取最大值作为结果 
	}else{
		for(d[x] = 1 ; d[x] <= 3 ; d[x] ++){         //通过递归定社团
			if(tong[d[x]] < n / 2){
				tong[d[x]] ++ ;
				dg(x + 1 , sum + a[x][d[x]]) ;       //sum剪枝 
				tong[d[x]] -- ;
			}
		}
	}
}
void init(){
	memset(tong , 0 , sizeof(tong)) ;
	memset(a , 0 , sizeof(a)) ;
	memset(d , 0 , sizeof(d)) ;
	n = ans = 0;
}
int main(){
	freopen("club.in" , "r" , stdin) ;
	freopen("club.out" , "w" , stdout) ;
	cin >> t ;
	while(t --){
		init() ;
		cin >> n ;                                     //输入n和n个人对于三个社团的满意度
		for(int i = 1 ; i <= n ; i ++){
			cin >> a[i][1] >> a[i][2] >> a[i][3] ;
		}
		dg(1ll , 0) ;
		cout << ans << endl ;
	}
	return 0;
}
