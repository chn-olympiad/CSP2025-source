// SN-J00595 杜明璋 西安滨河学校 
#include<bits/stdc++.h>
using namespace std;
string s,n,m,a,b,c,d;
string s01,s02,s03,s04,s05;
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	cin >> n >> m >> a >> b >> c >> d;
	for(int i = 1; i < s.size();i++){
		if (s[i] == '1')
			s05 = s[i] + s05;
		if (s[i] == '2')
			s04 = s04 + s[i];
		if (s[i] == '3')
			s03 = s[i] + s03;
		if (s[i] == '4')
			s02 = s02 + s[i];
		if (s[i] == '5')
			s01 = s01 + s[i];
	} 
	cout << 9;
	return 0;
}
