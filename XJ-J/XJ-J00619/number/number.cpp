#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int num = 1;
    char a[1005]={};
    cin>>s;
    for(int i = 0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[num] = s[i];
            num++;
        }
    }
    sort(a,a+num);
    for(int i = num-1;i>0;i--){
        if(a[i]!=' '){
            cout<<int(a[i]-48);
        }
    }
    return 0;
}
