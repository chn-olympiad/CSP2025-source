#include<bits/stdc++.h>
using namespace std;
char s[1005],gg[1005];
int top=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //scanf("%s",&s);
    cin.getline(s,1005);
    for(int i=1;i<=int(strlen(s));i++){
    	if((s[i]>='0')&&(s[i]<='9'))gg[top++]=s[i];
    }
    sort(gg+1,gg+top+1);
    for(int i=1;i<=top;i++){
    	printf("%c",gg[i]);
    }
	return 0;
}
