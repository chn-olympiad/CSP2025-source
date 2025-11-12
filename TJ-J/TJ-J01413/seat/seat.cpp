#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
想法：
1.输入教室的行和列，以及所有人的成绩
2.存下来小R的成绩，防止找错
3.把所有人的成绩按从小到大的顺序排好
4.填表，把每个位置都填上成绩
5.从表格中找到小R的成绩，并输出对应的行和列 
*/
ll n , m , a[100005] , q , ansh , ansl , g[1005][1005];
bool cmp(int x , int y){
	return x > y ;
}
void tianshu(){
	int temp = 0 ;
	for(int i = 1 ; i <= n ; i ++){
		if(i % 2 == 1){
			for(int j = 1 ; j <= m ; j ++){
				temp ++ ;
				g[i][j] = a[temp] ;
			}
		}else{
			for(int j = m ; j >= 1; j --){
				temp ++ ;
				g[i][j] = a[temp] ;
			}
		}
	}
}
int main(){
	freopen("seat.in" , "r" , stdin) ;
	freopen("seat.out" , "w" , stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n * m ; i ++){
		cin >> a[i] ;
	}
	q = a[1] ;
	sort(a + 1 , a + n * m + 1 , cmp) ;
	tianshu() ;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j <= m ; j ++){
			if(g[i][j] == q){
				cout << i << " " << j ;
			}	
		}
	}
}
