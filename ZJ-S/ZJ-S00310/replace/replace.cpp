#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, q;
string s1, s2;
string olds[N];
string news[N];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	cin >> n >> q;
	
	while(n --){
		cin >> s1 >> s2;
		olds[++ m] = s1, news[m] = s2; 
	}
	
	while(q --){
		cin >> s1 >> s2;
		if(s1.length() != s2.length()){
			puts("0");
			continue;
		}
		int k, ans = 0;
		for(int i = 1; i <= m; i ++){
			k = s1.find(olds[i]);
			if(k == -1) continue;
			if(s2.substr(k, olds[i].length()) == news[i]){
				string t = s2;
				for(int j = k; j <= olds[i].length() + k - 1; j ++)
					t[j] = olds[i][j - k];
				bool flag = true;
				for(int i = 0; t[i]; i ++)
					if(t[i] != s1[i]){
						flag = false;
						break;
					}
				if(flag) ans ++;
						
			} 
		}
		printf("%d\n ", ans);
			
	}
	
	
	return 0;
}