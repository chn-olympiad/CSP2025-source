#include <bits/stdc++.h>
using namespace std;

const int N=1e6+5;
char str[N];
int cnt[10];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",str+1); int n=strlen(str+1);
	for(int i=1;i<=n;i++) if(isdigit(str[i])) cnt[str[i]&15]++;
	for(int i=9;~i;i--) while(cnt[i]--) putchar(i|48);
	return putchar('\n'),0;
}
