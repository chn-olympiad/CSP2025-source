#include<bits/stdc++.h>
using namespace std;
int a[10]={0};
char s[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	int ls=strlen(s);
	for(int i=0;i<ls;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			printf("%d",i);
		}
	}
	return 0;
}
