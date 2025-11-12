#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[1000005];
int n,a[1000005],cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--){
		printf("%d",a[i]);
	}
	printf("\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}