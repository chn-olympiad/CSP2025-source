#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s ;
ll tong[15] ;
/*
想法：
1.输入字符串s
2.找到s中的每一个数字，并统计
3.倒着输出，从9开始一直到0，只要有这个数，就输出 
*/
int main(){
	freopen("number.in" , "r" , stdin) ;
	freopen("number.out" , "w" , stdout) ;
	cin >> s ;
	for(int i = 0 ; i < s.size() ; i ++){
		if(s[i] >= '0' && s[i] <= '9'){
			tong[s[i] - '0'] ++ ;
		}
	}
	for(int i = 9 ; i >= 0 ; i --){
		while(tong[i] != 0){
			cout << i ;
			tong[i] -- ;
		}
	}
}

