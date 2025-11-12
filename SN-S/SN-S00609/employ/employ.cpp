#include <iostream>
using namespace std;
long long sum = 1;
const int mod = 998224353;
int n,m,c;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++){
		cin >> c;
		if (c == 0){
			n--;
		}
	}
	if (n >= m){
		while (n > 0){
			sum = sum * n;
			n--;
		}
		cout << (sum + sum % mod) % mod;
	}
	else{
		cout << 0;
	}
	return 0;
}
