#include<bits/stdc++.h>
#define lint long long
using namespace std;
bool ip(char c){
	if(c >= '0' && c <= '9') return true;
	else return false;
}
int t[33];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int len = s.length();
	for(int i = 0;i < len;i++) if(ip(s[i])) t[s[i] - '0']++;
	for(int i = 9;i >= 0;i--){
		for(int j = 1;j <= t[i];j++) cout << i;
	}
	return 0;
}
