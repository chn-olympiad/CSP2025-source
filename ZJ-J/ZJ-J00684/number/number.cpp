#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
int a[N],cnt = 1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0;i < s.size();i++){
		if (s[i] >= 48 && s[i] <= 57){
			a[cnt] = s[i] - '0';
			cnt++;
		}
	}
	sort(a+1,a+cnt);
	for (int i = cnt - 1;i >= 1;i--){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
