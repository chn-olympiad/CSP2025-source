#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];
int main(){
	freopen("number.in","R",stdin);
	freopen("number.out","W",stdout);
	scanf("%s",s+1);
	int g=1;
	int l=strlen(s+1);
	for(int i=1;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[g++]=s[i]-'0';
		}
	}
	sort(a+1,a+g+1);
	for(int i=g;i>1;i--){
		cout<<a[i];
	}
	return 0;
} 
