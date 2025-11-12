#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
string s;
long long a[N] , len;

bool cmp(long long a , long long b){
	return a > b;
}

int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	
	for(long long i = 0;i < s.size(); i++){
		if(s[i] >= '0' && s[i] <= '9') a[++len] = s[i] - '0';
	}
	
	sort(a + 1, a + len + 1, cmp);
	
	for(long long i = 1; i <= len; i++){
		cout << a[i];
	}
	
	return 0;
}