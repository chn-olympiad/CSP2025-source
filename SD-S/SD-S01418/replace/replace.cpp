#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;;
int n, m;
string s[N][10];
int a[N][5];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> s[i][1] >> s[i][2];
		for(int j = 0; j <= s[i][1].size(); j ++){
			if(s[i][1][j] == 'b') a[i][1] = j; 
			if(s[i][2][j] == 'b') a[i][2] = j;
		}
	}
	string t1, t2;
	while(m --){
		cin >> t1 >> t2;
		int x, y;
		for(int i = 0; i < t1.size(); i ++){
			if(t1[i] == 'b') x = i;
			if(t2[i] == 'b') y = i;
		}
		int ss = 0;
		for(int i = 1; i <= n; i ++){
			int f = s[i][1].size();
			if(x >= a[i][1] && a[i][2] - a[i][1] == y - x && f - a[i][1] <= t1.size() - x) ss ++;
		}
		cout << ss << endl ;
	}
}
