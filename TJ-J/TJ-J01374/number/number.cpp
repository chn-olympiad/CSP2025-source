#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string s;
int b[1000005],k=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            b[k++]=s[i]-'0';
            //cout<<b[k-1];
        }
    }
    sort(b+1,b+k+1);
    //for(int i=1;i<=k;i++)cout<<b[i];
    for(int i=k;i>1;i--)cout<<b[i];
    return 0;
}
