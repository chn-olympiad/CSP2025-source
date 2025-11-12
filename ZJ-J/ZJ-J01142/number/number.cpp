#include <bits/stdc++.h>
using namespace std;
int t[10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::string s;
	std::cin>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]-'0'>=0&&s[i]-'0'<=9) {
			t[s[i]-'0']+=1;
		}
	}
	for(int i=9; i>=0; i--) {
		for(int j=0; j<t[i]; j++) {
			std::cout<<i;
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
