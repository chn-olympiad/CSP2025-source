#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<cstdio>
using namespace std;
string a, b;
int n = 10, ans[10001], m = 0, temp = 0;
int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	b = a;
	for(int i = 1; i<= a.length(); i++){
		
	}
	//int l = s.lenth();
//	for(int i = 0; i == 1;){
//		b = a;
//		b /= n;
//		b %= 10;
//		if(b >= 0 && b <= 9){
//			ans[m] = b;
//			m++;
//		}
//		if()
//	}
	while(1){
		b /= 10;
		l++;
		if(b == 0) break;
	}
	for(int i = 0; i <= a.lenth(); i++){
		b = b % n;
		if(int(b) > 0 && int(b) < 9){
			temp++;
			ans[temp] = b;
		}
		b = a;
		n *= 10;
	}
	return 0;
}
