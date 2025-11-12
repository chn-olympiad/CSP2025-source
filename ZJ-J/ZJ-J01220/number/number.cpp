#include<bits/stdc++.h>
using namespace std;
string s;
string ans;
int buc[15];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char x:s) {
		if(isdigit(x)) {
			buc[x-'0']++;
		}
	}
	for(int i=9; i>=0; i--) {
		while(buc[i]>0) {
			buc[i]--;
			cout<<i;
		}
	}
	return 0;
}
