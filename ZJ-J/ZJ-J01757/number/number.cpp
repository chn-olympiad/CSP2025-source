#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 1e6 + 5;
string str;
int num[N], cnt;
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> str;
	for(int i = 0;i < str.size();i ++){
		if('0' <= str[i] && str[i] <= '9'){
			num[++ cnt] = str[i] - '0';
		}
	}
	sort(num + 1, num + cnt + 1);
	if(num[cnt] == 0){
		cout << 0;
		return 0;
	}
	for(int i = cnt;i >= 1; i --){
		cout << num[i];
	}
	return 0;
}
