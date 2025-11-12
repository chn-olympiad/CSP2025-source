#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int n, q, s_s, sum, t_s;
string s1[N], s2[N], t1, t2;

bool check(int i,int n){
	while(s_s--){
		s_s--;
		if(s1[i][s_s] != t1[n + s_s] && s2[i][s_s] != t2[n + s_s]) return 0;
	}
	return 1;
}
void run(int sum){
	for (int i = 1; i <= n; i++){
		s_s = s1[i].size();
		for (int j = 0; j < t_s - s_s; j++){
			if (check(i, j)){
				sum++;
			}
		}
	}
	cout << sum << endl;
}


int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++){
		cin >> t1 >> t2;
		t_s = t1.size();
		run(0);
	}
	
	
	
	
	
	
	
	
	return 0;
}
