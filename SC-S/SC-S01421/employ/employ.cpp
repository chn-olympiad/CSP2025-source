#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	int n , m;cin >> n >> m;
	string s;cin >> s;
	for(int i = 0 , x;i < n;i++) cin >> x;
	cout << n * (n - 1) / 2;
	return 0;
	fclose(stdin);
	fclose(stdout);
}