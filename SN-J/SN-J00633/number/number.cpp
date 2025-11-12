#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000000];
	string n;
	int m = 0;
	cin >> n;
	for (int i = 0;i < n.length();i++){
		if (n[i] >= '0' && n[i] <= '9'){
			a[m] = n[i];
			m++;
		}
	}
	sort(a,a+m);
	for (int i = m;i >= 0;i--){
		cout << a[i];
	}
	return 0;
}
