#include <bits/stdc++.h>
using namespace std;
char s[1010000];
int c[110],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(c[i]--){
			printf("%d",i);
		}
	}
	
	
	return 0;
}
