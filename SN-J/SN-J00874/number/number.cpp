// SN-J00874 管怡信 富阎高新初级中学
#include <bits/stdc++.h>
using namespace std;
int m,Max;
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i<s.size();i++){
		if (s[i]>='0'&&s[i]<='9'){
			cout <<s[i];
		}
	}
	return 0;
}
