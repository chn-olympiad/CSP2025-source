#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a[1000001] = {} , s , b;
	int cnt = 0 , j = 0;
	cin >> s;
	for(int i = 0 ; i < s.length() ; i++){
		if(s[i] <= '9' && s[i] >= '0'){
			cnt++;
			a[cnt] = s[i];
		}
	}
	sort(a , a + cnt + 1);
	for(int i = cnt; i >= 1; i--){
		b = b + a[i];
		j++;
	}
	cout << b;
	return 0;
}
