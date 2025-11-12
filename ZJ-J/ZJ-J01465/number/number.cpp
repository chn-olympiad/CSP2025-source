#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) if(s[i]>='0'&&s[i]<='9') a[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        while(a[i]--) putchar(i+'0');
    puts("");
    return 0;
}
//feropen("number.out","r",stdin);
//feropen("number.in","w",stdout);