#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int x,int y)
{
    return x>y;
}

int a[1000001]={};

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,i,cnt=0;
    string s;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++)
    {
        if(isdigit(s[i]))
        {
            a[++cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(i=1;i<=cnt;i++)
    {
        cout<<a[i];
    }
}
