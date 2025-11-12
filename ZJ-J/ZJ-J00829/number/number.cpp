#include<bits/stdc++.h>
using namespace std;
int a[1000010];
char s[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int ls=strlen(s+1);
    int la=0;
    for(int i=1;i<=ls;i++)
        if(s[i]>='0'&&s[i]<='9')
            a[++la]=s[i]-'0';
    sort(a+1,a+la+1);
    for(int i=la;i>=1;i--)
        printf("%d",a[i]);
    return 0;
}
