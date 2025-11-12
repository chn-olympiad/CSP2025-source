#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s="";
    cin>>s;
    int num[100004]={},indexx=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[indexx]=s[i]-'0';
            indexx++;
        }
    }
    sort(num,num+indexx);
    for(int i=indexx-1;i>=0;i--) cout<<num[i];
    return 0;
}
