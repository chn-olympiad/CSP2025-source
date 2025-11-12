//9:40 四道题初步写完 100+100+60+64 = 324
//9:50 T3正解  100+100+100+64 = 364
#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(char i = '9'; i>='0'; i--) {
		for(int j = 0; j<a.size(); j++) {
			if(a[j]==i) {
				cout<<a[j];
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
