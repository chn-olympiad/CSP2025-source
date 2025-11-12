#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a=0;
int num[N];
int cnt=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]<'a'){
            a*=10;
            a+=s[i]-'0';
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++){
        num[i]=a%10;
        a/=10;
    }
    sort(num,num+1+cnt);
    for(int i=cnt;i>0;i--) cout<<num[i];
    return 0;
}
