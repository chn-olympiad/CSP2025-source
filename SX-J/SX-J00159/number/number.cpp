#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];
int t=0;
int main(){
	scanf("%s",s+1);
	for (int i=1;i<=strlen(s+1);i++){
		if (s[i]>='0' && s[i]<='9'){
			a[++t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1);
	for (int i=t;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}