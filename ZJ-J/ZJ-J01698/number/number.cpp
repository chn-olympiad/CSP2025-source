#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 200;
int a[N];
bool cmp(int a , int b){
	return a > b;
}
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	int c = 0;
	for(int i = 0 ; i < s.size(); i ++){
		int x;
		x = s[i] - '0';
		if(x <= 9 && x >= 0) a[++ c] = x;
	}
	sort(a + 1 , a + c + 1 , cmp);
	for(int i = 1; i <= c; i ++)
		cout << a[i];
	return 0;
}
