#include<bits/stdc++.h>
using namespace std;
char s[1000001];
int l,cnt['0' + 10];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	l = strlen(s);
	for(int i = 0; i < l; ++i) if('0' <= s[i] && s[i] <= '9') ++cnt[s[i]];
	for(int i = '9'; i >= '0'; --i) while(cnt[i]--) printf("%c",i);
	return 0;
}
