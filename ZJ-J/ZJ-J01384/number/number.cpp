#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char ch[1000020];
int len;
bool cmp(char x,char y)
{
    return int(x)<int(y);
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>ch;
    len=strlen(ch);
    sort(ch,ch+len,cmp);
    int i;
    for(i=0;i<len;i++)
        if(ch[i]<'0'||ch[i]>'9') break;
    for(int j=i-1;j>=0;j--) cout<<ch[j];
    return 0;
}
//#Shang4Shan4Ruo4Shui3
