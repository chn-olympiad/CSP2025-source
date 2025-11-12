#include <bits/stdc++.h>
using namespace std;
long long cnt[15];
string s;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> s;
	
	int cnt_n = 1;
	for (int i = 0;i < s.size();i++){
		char x = s[i];
		if ('0' <= x && x <= '9'){
		    int num = x - '0';
		    cnt[num]++;
		}
	}
	for (int i = 9;i >= 0;i--){
		for (int j = 1;j <= cnt[i];j++){
			cout << i;
		}
	}
	return 0;
}
