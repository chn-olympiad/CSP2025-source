#include<bits/stdc++.h>
using namespace std;
string str;
int num [1000000];
int numi;

int main () {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> str;
	for (int i=0; i<str.size(); i++) {
		if (str[i]-'0'>=0&&str[i]-'0'<=9) {
			num[numi]=str[i]-'0';
			numi++;
		}
	}
	sort (num,num+numi);
	for (int i=numi-1; i>=0; i--) {
		cout << num[i];
	}
	return 0;
}
