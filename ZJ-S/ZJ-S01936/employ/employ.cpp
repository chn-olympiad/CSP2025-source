#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[500];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] = 0) cnt++;
	}
	long long sum = 1;
	for(int i = 1; i <= n - cnt; i++){
		sum = sum * i % 998244353;
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
