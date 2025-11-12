#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[1000005],a = 1,z = 0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] <= '9' && s[i] >= '0'){
			cnt[a] = int(s[i] - '0');
			a++;
		}
	}
	a--;
	sort(cnt + 1,cnt + 1 + a);
	for(int i = a;i > 0;i--) cout << cnt[i]; 
	return 0;
}
