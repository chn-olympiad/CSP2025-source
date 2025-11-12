#include<bits/stdc++.h>
using namespace std;
char s[1000002];
int l;
int tot[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			++tot[s[i]-'0'];
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=tot[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}