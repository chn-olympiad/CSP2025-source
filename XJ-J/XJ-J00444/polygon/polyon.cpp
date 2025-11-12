#include <bits/stdc++.h>
using namespace std;
int shu[1000010]
int s;
int main(){
    //freopen("number.in", "r", stdin);
    //freopen("number.out", "w", stdout);
    getline(cin,s);
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]>='1' && s[i]<='9')
        {
            shu[i]=s[i];
        }
    }
    sort(1,shu+1);
    for(int i=0;i<s.size();i++)
    {
        cout<<shu[i];
    }
    return 0; 
