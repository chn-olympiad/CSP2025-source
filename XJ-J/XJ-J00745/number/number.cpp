#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+16;
long long t[16];
char s[MAXN];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]<='9'&&s[i]>='0')t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(t[i]--)printf("%d",i);
	}
	//rp++
	return 0;
}
