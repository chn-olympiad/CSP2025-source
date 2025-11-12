#include <bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	int n,m,s[100],a;
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++){
		cin >> s[0];
		s[0] = a;
		for (int i = 0;i <= n;i++){
			if (s[i] < s[i-1]){
				int j = s[i];
				s[i] = s[i-1];
				s[i-1] = j;
			}
		}
		
	}
	for (int b = 1;b <= n*m;b++){
		if (a = s[0]){
			cout << 1 << " " << 1;
		}
		else if (a = s[b]){
			cout << 1 << " " << b;
		}
		else if (a = s[b+1]){
			cout << 2 << " " << b;
		}
		else if (a = s[2*b]){
			cout << 2 << " " << 1;
		}
		else if (a = s[2*b+1]){
			cout << 3 << " " << 1;
		}
	}
	return 0;
}
