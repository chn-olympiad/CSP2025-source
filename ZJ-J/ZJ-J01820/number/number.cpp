#include<stdio.h>
#include<string.h>
/*O(n)*/
namespace{
	char s[1000005];
	int num[10],n;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) if('0'<=s[i]&&s[i]<='9') num[s[i]-'0']++;
	for(int i=9;~i;i--) while(num[i]--) printf("%d",i);
	fclose(stdin);fclose(stdout);
	return 0;
}