#include<bits/stdc++.h>
using namespace std;
int a[1000010],s,a;
int main(){
    string ans;
    cin>>s;
    freopen("number.1",stdin);
    for(int i=0;i<=s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9'){
            a[i]=s[i];
        }
    }

    for(int i=1;i<=s.size();i++)
    {
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}
