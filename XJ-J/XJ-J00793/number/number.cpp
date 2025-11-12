#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 1e6 + 10;

int n = 1, a[N];
string s;

bool cmp(int p, int q){
	return p > q;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] <= '9' && s[i] >= '0'){
			a[n++] = s[i] - '0';
		}
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i ++){
		cout << a[i];
	}
	return 0;
}
