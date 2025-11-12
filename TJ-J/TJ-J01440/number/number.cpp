#include <iostream>
#include <cstdio>
using namespace std;

int sum[15];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            sum[s[i]-'0']++;
        }
    }
    bool flag=true;
    for(int i=9;i>=1;i--){
        while(sum[i]--){
            cout << i;
            flag=false;
        }
    }
    if(flag){
        cout << 0;
    }else{
        while(sum[0]--){
            cout << 0;
        }
    }
    return 0;
}
