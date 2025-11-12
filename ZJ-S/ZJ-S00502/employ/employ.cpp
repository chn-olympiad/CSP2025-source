#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	if(m == n){
		for(int i = 0;i < n;i++){
			if(s[i] == '0'){
				cout << 0;
				return 0;
			}
		}	
	}
	return 0;
}