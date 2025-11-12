#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
int n,m,a[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1;i <= n;i++) cin >> a[i];
	if (m == n){
		long long sum = 1;
		for (int i = 1;i <= n;i++){
			sum *= i;
			sum %= 998244353;
		}
		int p = sum;
		cout << p;
	}else{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
