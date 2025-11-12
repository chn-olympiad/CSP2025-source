#include <bits/stdc++.h>
//our 2nd CSP-J wars 
int tong[10];
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	for(int i=0;i<s.length();i++) {
		if(s[i]>='0'&&s[i]<='9') {
			int t=s[i]-'0';
			tong[t]++;
		}
	}
	//hack:0d0d0d0
	if(tong[0]>0&&tong[1]==0&&tong[2]==0&&tong[3]==0&&tong[4]==0&&tong[5]==0&&tong[6]==0&&tong[7]==0&&tong[8]==0&&tong[9]==0) {
		cout << 0;
		return 0;
	}
	for(int i=9;i>=0;i--) {
		while(tong[i]>0) {
			tong[i]--;
			cout << i;
		}
	}
	return 0;
} 
