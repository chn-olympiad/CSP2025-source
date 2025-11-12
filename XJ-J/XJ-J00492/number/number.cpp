# include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
char c[N];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, s1 = "";
	getline(cin, s);
	
	long long len = s.size();
	for (int i = 0; i < len; i++){
		if (s[i] >= '0' && s[i] <= '9'){
			s1 += s[i];
		}
	}
	
	long long len1 = s1.size();
	for (int i = 0; i < len; i++){
		c[i] = s1[i];
	}
	
	sort(c, c + len1, cmp);	
	
	for (int i = 0; i < len; i++){
		cout << c[i];
	}	
	return 0;
}
