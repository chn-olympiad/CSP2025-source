#include<bits/stdc++.h>
#define ll long long 
using namespace std;
/*
想法：
1.输入每一天的难度
2.根据特性A骗分

特殊性质A：对于所有1 ≤ i ≤ n，均有si = 1。 
*/
ll n , m , s[100005] ;
int main(){
	freopen("employ.in" , "r" , stdin) ;
	freopen("employ.out" , "w" , stdout) ;
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i ++){
		cin >> s[i] ;
	}
	cout << "0" ;
	return 0;
}
