#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string st;
int a[N];
int cnt;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> st;
	for(int i = 0; i < st.size(); i++){
		if(st[i] >= '0' && st[i] <= '9'){
			a[++cnt] = st[i] - '0';
		}
	}
	sort(a + 1, a + 1 + cnt);
	for(int i = cnt; i >= 1; i--){
		printf("%d", a[i]);
	}
	return 0;
}
