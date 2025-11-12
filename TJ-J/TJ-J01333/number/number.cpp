#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b)
{
    return a>b;
}
char c[1000005];
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    vector<char> vct;
    cin>>c;
    for(int i=0;i<strlen(c);i++)
    {
        if(c[i]>='0'&&c[i]<='9')
        {
            vct.push_back(c[i]);
        }
    }
    sort(vct.begin(),vct.end(),cmp);
    vector<char>::iterator it;
    for(it=vct.begin();it!=vct.end();it++)
    {
        cout<<*it;
    }
    return 0;
}
