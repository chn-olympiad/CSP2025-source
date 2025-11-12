#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char c;
	while(cin.good()) {
		cin.get(c);
		if(isdigit(c))
			s+=c;
	}
	sort(s.rbegin(),s.rend());
	cout<<s<<endl;
	return 0;
}