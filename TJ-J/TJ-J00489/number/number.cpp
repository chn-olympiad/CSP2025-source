#include <bits/stdc++.h>
using namespace std;
string s;
int a[100005] , l;
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	cin >> s;
	int len = s.size();
	for(int i = 0;i < len;i++){
		if(isdigit(s[i])) a[l++] = (s[i] - '0');
	}
	sort(a , a + l);
	for(int i = l - 1;i >= 0;i--) cout << a[i];
	return 0;
}  
