#include <bits/stdc++.h>
using namespace std;
int num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt = 1;
	string s;
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num[cnt] = s[i] - '0';
			cnt++;
		}
	}
	cnt--;
	sort(num+1,num+cnt+1);
	for(int i = cnt;i >= 1;i--) cout << num[i];
	return 0;
}
