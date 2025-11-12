#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
long long a[1000001];
char c[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	long long num = s.size();
	for(int i = 0;i < num;i++){
		c[i] = s[i];
		if(num == 1){
			cout << c[i] - '0';
			return 0;
		}
		if(c[i] - '0' >= 0 && c[i] - '0' <= 9){
			a[i] = c[i] - '0';
			n++;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n - 1;j++){
			if(a[i+1] > a[j]){
				swap(a[i+1],a[j]);
			}
		}
	}
	for(int i = 0;i < n;i++){
		cout << a[i];
	}
	return 0;
}
