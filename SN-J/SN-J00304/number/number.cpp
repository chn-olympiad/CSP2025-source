#include <bits/stdc++.h>
using namespace std;
int arr[15];
string a;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a.size(); i ++){
			if (a[i] - '0' >= 0 ||  a[i] - '0' <= 9) arr[a[i] - '0'] ++;
	}
	for (int i = 9; i >= 0; i --){
		while (arr[i] --) printf("%d", i);
	}
	return 0;
}
