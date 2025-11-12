#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

const int N = 100010;

map <string, string> s;
string S;
int cnt;

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		string s1, s2;
		cin >> s1 >> s2;
		s[s1] = s2;
	}
	while(q --){
		string s1, s2;
		cin >> s1 >> s2;
		int n = s1.size(), m = s2.size();
		if(n != m) {
			cout << 0 << endl;
			continue;
		}
		int l = 0, r = 0;
		for(int i = 0; i < n; i ++)
			if(s1[i] != s2[i]) {
				l = i; 
				break;
			}
			
		for(int i = n - 1; i > 0; i --)
			if(s1[i] != s2[i]) {
				r = i; 
				break;
			}
		//if(l == 0 && r == 0 && s1[0] == s2[0]) {cout << 0 << endl; break;}
		for(int i = 0; i <= l; i ++)
			for(int j = r; j < n; j ++){
				string s3, s4;
				for(int k = i, kk = 0; k <= j;k ++, kk ++){
					s3 += s1[k];
					s4 += s2[k];
				}
				if(s[s3] == s4 && s[s3] != S)
					cnt ++;
			}
		cout << cnt << endl;
		cnt = 0;
	}
	
}
