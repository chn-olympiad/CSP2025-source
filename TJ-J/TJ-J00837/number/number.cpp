#include <cstdio>
#include <cstring>
const int N=1000007;
char s[N];
int c[10];

int len=0;
char ans[N];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++) if ('0'<=s[i] && s[i]<='9') {
		c[s[i]-'0']++;
	}
	for (int _=1;_<=9;_++) if (c[_]) {
		for (int i=9;i>=0;i--) {
			for (int j=1;j<=c[i];j++) ans[++len]='0'+i;
		}
		printf("%s",ans+1);
		return 0;
	}
	puts("0");
	return 0;
}
