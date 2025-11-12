#include<bits/stdc++.h>
using namespace std;
long long w[1000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,q;
    long long sum=0;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            q+=s[i];
            sum++;
        }
    }
    for(int i=1;i<=q.length();i++)
    {
        w[i]=(q[i-1]-'0');
    }
    sort(w+1,w+sum+1);
    for(int i=sum;i>=1;i--)
    {
        cout<<w[i];
    }
    return 0;
}
