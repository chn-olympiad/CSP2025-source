#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
string s;
int a[N];

bool cmp(int x,int y) {
	return x > y;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int sum = 0;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9') {
			sum ++;
			a[i] = (int(s[i]) - '0');	
		}
	}
	sort(a,a + s.size(),cmp);
	for(int i = 0;i < sum;i++){
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
