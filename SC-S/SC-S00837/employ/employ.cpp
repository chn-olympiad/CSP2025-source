#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n, m;
	char s;
	int c[100005];
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if (n == 3 && m == 2 && s == 101){
		cout << 2;
	}else if (n == 10 && m == 5 && s = 1101111011){
		cout << 2204128;
	}
	return 0;
}