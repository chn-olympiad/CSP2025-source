#include<bits/stdc++.h>
using namespace std;
char ch[1000105];
int a[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",ch);
	int l=strlen(ch);
	for(int i=0;i<l;i++){
		if(ch[i]>='0'&&ch[i]<='9'){
			a[ch[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			putchar(i+'0');
			a[i]--;
		}
	}
	return 0;
}
