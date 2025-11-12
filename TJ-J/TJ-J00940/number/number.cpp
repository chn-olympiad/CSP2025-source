#include <bits/stdc++.h>
using namespace std;
#define endl '\n' 
string a,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for (int i = 0;i<a.size();i++){
		if (a[i] >= '0' && a[i] <= '9'){
			b += a[i];
		}
	}
	for (int i = 0;i<b.size();i++){
		for (int j = i;j<b.size();j++){
			if (b[i] <= b[j]) swap(b[i],b[j]);
		}
	}
	cout << b;
	return 0;
}
