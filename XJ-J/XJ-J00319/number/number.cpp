#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N];
int a[N],n,cnt=1;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=strlen(s);
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<cnt;i++)cout<<a[i];
    return 0;
}