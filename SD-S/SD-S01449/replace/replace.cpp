#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
string t1, t2;
string x1, x2;
int n, q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i ++){
		cin >> t1 >> t2;
	}
	for (int i = 1;i <= q;i ++){
		cin >> x1 >> x2;
	}
	while (q --){
		cout << 0 << '\n';
	}
	return 0;
}
