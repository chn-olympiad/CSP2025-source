// SN-J00595 杜明璋 西安滨河学校 
#include<bits/stdc++.h>
using namespace std;
string s,a[1000005];
string s10,s11,s12,s13,s14,s15,s16,s17,s18,s19;
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	cin >> s;
	for(int i = 0; i < s.size();i++){
		if (s[i] == '0')
			s10 = s10 + s[i];
		if (s[i] == '1')
			s11 = s[i] + s11;
		if (s[i] == '2')
			s12 = s12 + s[i];
		if (s[i] == '3')
			s13 = s[i] + s13;
		if (s[i] == '4')
			s14 = s14 + s[i];
		if (s[i] == '5')
			s15 = s[i] + s15;
		if (s[i] == '6')
			s16 = s16 + s[i];
		if (s[i] == '7')
			s17 = s[i] + s17;
		if (s[i] == '8')
			s18 = s18 + s[i];
		if (s[i] == '9')
			s19 = s[i] + s19;
	}
	cout << s19 << s18 << s17 << s16 << s15 << s14 << s13 << s12 << s11 << s10; 
	return 0;
}
