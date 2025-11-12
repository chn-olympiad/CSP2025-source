#include <bits/stdc++.h>
using namespace std;
string s,num,ans;
//int cmp(char x,char y){
//	if(x >= '0' and x <= '9' and (y > '9' or y < '0')){
//		return x > y;
//	}else if(x - 48 > y - 48){
//		return x > y;
//	}
//}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> s;
	// sort(s.begin,s,end,cmp);
	for(int i = 0;i < s.size();i++){
		if(s[i] >= '0' and s[i] <= '9'){
			num = s[i] + num;
		}
	}
	sort(num.begin(),num.end());
	for(int i = num.size() - 1;i >= 0;i--){
		ans = ans + num[i];
	}
	cout << ans << "\n";
	return 0;
}
