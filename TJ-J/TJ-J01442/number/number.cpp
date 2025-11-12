#include <bits/stdc++.h>
#define int long long
using namespace std;
char ch[1000010];
int cnt[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",ch + 1);
	int len = strlen(ch + 1);
	for (int i = 1;i <= len;i++){
		if ('0' <= ch[i] && ch[i] <= '9'){
			cnt[ch[i] - '0']++;
		}
	}
	for (int i = 9;i >= 0;i--){
		for (int j = 0;j < cnt[i];j++){
			putchar(char(i + '0'));
		}
	}
	return 0;
}
