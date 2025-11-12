#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int n,m;         
int a[110];

bool cmp( int x, int y ){
	return x > y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for( int i = 1; i <= n *m; i++ ){
		cin >> a[i];
	}
	int x = a[1];
	sort( a + 1, a + n * m + 1, cmp); 
	for( int i = 1; i <= n * m;i ++ ){
		if( a[i] == x ){
			x = i;
			break;
		}
	}
	//数学逻辑运算
	if( x % n == 0 ){  //特判：x被n整除 
		cout << x /n << " " << n;
		return 0;
	}
	int c = ( x / n ) + 1; //列 
	// true正序 false倒序
	if( c % 2 != 0 ){
		int r = x % n;
		cout << c << " " << r;
	}
	else{
		int r = x % n;
		cout << c << " " << n-r+1;
	}
	return 0;
} 
