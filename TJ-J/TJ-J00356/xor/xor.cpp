#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100010];
int ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for( int i = 1; i <= n; i++ ){
		scanf("%d",&a[i]);
	}
	int cnt = 0;
	for( int i = 1; i <= n; i++ ){
		cnt = cnt ^ a[i];
		if( cnt == k ){
			cnt = 0;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
