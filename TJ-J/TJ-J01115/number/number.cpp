#include <bits/stdc++.h>
using namespace std;
string s;
int num[1000005],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' && s[i] <= '9'){
			num[++n] = s[i]-'0';
		}
	}
	sort(num,num+n+1);
	for(int i = n;i >= 1;i--){
		cout << num[i];
	}
	return 0;
}
