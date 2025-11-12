#include<bits/stdc++.h>
using namespace std;

int n,gs[15];
char s[1000010];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if('0'<=s[i]&&s[i]<='9')
			gs[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=gs[i];j++)
			printf("%d",i);
	printf("\n");
	return 0;
}
