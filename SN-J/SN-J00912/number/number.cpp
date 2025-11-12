#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(char x,char y){
	return x >= y;
}
char s[1000005];
string m;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> m;
	int n = m.length(),x = 0;
	for (int i = 0; i < n; i++){
		if ('0' <= m[i] && '9' >= m[i]){
			s[++x] = m[i];
		}
	}
	sort(s + 1,s + x + 1,cmp);
	for (int i = 1; i <= x; i++){
		cout << s[i];
	}
	return 0;
}
