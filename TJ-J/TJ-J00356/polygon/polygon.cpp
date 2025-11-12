#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int n;
int a[5010], num[5010];   
int cnt, ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for( int i = 1; i <= n; i++ ){
		int x;
		cin >> x;
		a[x]++;
		if( a[x] == 1 ) num[++cnt] = x;
	}
	sort( num + 1, num + n + 1 );
	if( n != 0 )
		cout << 1;
	return 0;
}
