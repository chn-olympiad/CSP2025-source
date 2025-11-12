#include<bits/stdc++.h>
using namespace std;

string my_s;
int arr[15];

int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,my_s);
	for(int i = 0; i < my_s.size(); ++i) {
		if(my_s[i] >= '0' && my_s[i] <= '9') ++arr[my_s[i] - '0'];
	}
	for(int i = 9; i >= 0; --i) {
		while(arr[i] != 0) {
			cout << i;
			--arr[i];
		}
	}
	return 0;
}
