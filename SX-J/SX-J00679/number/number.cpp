#include <bits/stdc++.h>
using namespace std;
int a[20];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;

	int len = s.size();
	for(int i = 0; i < len; i++) {
		if(s[i]=='0') a[0]++;
		if(s[i]=='1') a[1]++;
		if(s[i]=='2') a[2]++;
		if(s[i]=='3') a[3]++;
		if(s[i]=='4') a[4]++;
		if(s[i]=='5') a[5]++;
		if(s[i]=='6') a[6]++;
		if(s[i]=='7') a[7]++;
		if(s[i]=='8') a[8]++;
		if(s[i]=='9') a[9]++;
	}
	
	for(int i = 9; i >= 0; i--){
		for(int j = 1; j <= a[i]; j++){
			printf("%d",i);
		}
	}

	return 0;
}
