// 曲江第一学校 SN-J00231 姚奕辰
#include <bits/stdc++.h>
#define int long long
using namespace std;
int cmp(int x,int y){
	return x > y;
}
string s;
char a[1000005];
int cnt = 0;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i = 0;i <= s.size();i ++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			continue;
		}
		else{
			cnt ++;
			a[i] = s[i];
		}
	}
	sort(a,a + s.size(),cmp);
	for(int i = 0;i < cnt;i ++){
		cout << a[i];
	}
	return 0;
}
