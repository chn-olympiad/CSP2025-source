#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005], num;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if((int)s[i] >=48 && (int)s[i] <= 57){
			a[i] = (int)s[i] - 48;
			num++;
		}
	}		
	for(int i = 0;i < num;i++){
		for(int j = 0;j < num;j++){
			if(a[j] < a[j + 1]){
				int c = a[j + 1];
				a[j + 1] = a[j];
				a[j] = c;
			}
		}
	}
	for(int i = 0;i < num;i++){
		cout << a[i];
	}
	return 0;
}
