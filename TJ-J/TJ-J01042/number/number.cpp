#include<bits/stdc++.h>
using namespace std;
int t[20];
char c;
int x;
string ans;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>c&&c!='\n'){
        if(c>='0'&&c<='9'){
            x=c-'0';
            t[x]++;
        }
    }
    for(int i=9;i>=0;i--){
        if(t[i]){
            while(t[i]){
                ans+=i+'0';
                t[i]--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
