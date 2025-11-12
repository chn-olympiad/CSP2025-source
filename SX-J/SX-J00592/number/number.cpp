#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1),cnt=0;
	for(int i=1;i<=n;i++){
		if('0'<=s[i]&&s[i]<='9') cnt++,s[cnt]=s[i];
	}
	sort(s+1,s+cnt+1);
	reverse(s+1,s+cnt+1);
	for(int i=1;i<=cnt;i++) printf("%c",s[i]);
	return 0;
}
