#include <bits/stdc++.h>;
using namespace std;
char s[1000010];
int a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",s+1);
    int l=strlen(s+1),x=1;
    for (int i=1;i<=l;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[x]=s[i]-'0';
            x++;
        }
    }
    sort(a+1,a+x+1);
    for (int i=x;i>1;i--)
            printf("%d",a[i]);
    return 0;
}
