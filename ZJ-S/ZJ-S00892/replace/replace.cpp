#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int ptc=2e5+10;
unordered_map<int,int>rx;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    bool bs=1;
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    {
        string s,s2;
        cin>>s>>s2;
        int p1=0,p2=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='b')p1=i;
            else if(s[i]!='a')bs=0;
            if(s2[i]=='b')p2=i;
            else if(s2[i]!='a')bs=0;
        }
        rx[p2-p1]++;
    }
    if(bs==0)
    {
        while(q--)puts("0");
        return 0;
    }
    while(q--)
    {
        string s,s2;
        cin>>s>>s2;
        if(s.length()!=s2.length())
        {
            puts("0");
            continue;
        }
        int p1=0,p2=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='b')p1=i;
            else if(s[i]!='a')bs=0;
            if(s2[i]=='b')p2=i;
            else if(s2[i]!='a')bs=0;
        }
        if(bs==0)puts("0");
        printf("%d\n",rx[p2-p1]);
    }
    return 0;
}
