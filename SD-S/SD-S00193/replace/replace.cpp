#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

const int N = 2e5+10;

int n , m;
string u[N] , v[N];

void bl1();

int main() {
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	
	scanf("%d%d" , &n , &m);
	for(int i = 1 ; i <= n ; i ++) {
		cin >> u[i] >> v[i];
	} 
	
//	if(n <= 1e3 && m <= 1e3) {
		bl1();
//		return 0;
//	}
	
	return 0;
}

void bl1() {
	// 24pts
	string a , b;
	while(m --) {
		cin >> a >> b;
		if(a.size() != b.size()) {
			puts("0");
			continue;
		}
		int res = 0 , lst;
		for(int i = a.size()-1 ; i >= 0 ; i --)
			if(a[i] != b[i]) {
				lst = i+1;
				break;
			}
		
		for(int pos = 0 ; pos < a.size() ; pos ++) {
			for(int i = 1 ; i <= n ; i ++) {
				bool flag = true;
				if(pos+u[i].size() > a.size()) continue;
				for(int j = 0 ; j < u[i].size() ; j ++) {
					if(a[pos+j] != u[i][j]
						|| b[pos+j] != v[i][j]) {
						flag = false;
						break;
					}
				}
				
				if(flag && pos+u[i].size() >= lst) {
					res ++;
				}
			}
			if(a[pos] != b[pos]) break;
		}
		
		printf("%d\n" , res);
	}
}
