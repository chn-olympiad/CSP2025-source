#include<bits/stdc++.h>
using namespace std;
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
#define endl '\n'

/*
仔细仔细再仔细！
认真认真再认真！

十年 OI 一场梦，不开 ll 见祖宗
30 分钟必须跳，文件核对别爆零
多找规律试暴力，别把满分当一切
*/

// 0840 AC O(|s|) = 1e6
// 1131 i cant earn anymore!
constexpr int N = 1e6 + 5;
char s[N];
bool cmp(char a,char b){
	if(isdigit(a) && isdigit(b))return (a - '0') > (b - '0');
	if(!isdigit(a))return false;
	if(!isdigit(b))return true;
}
signed main(){
	fileIO("number");
	cin.tie(0),cout.tie(0);
	cin >> s;
	string t = s;
	sort(s,s + t.size(),cmp);
	for(int i = 0;;i ++){
		if(isdigit(s[i]))cout << s[i];
		else break;
	}
	return 0;
}

