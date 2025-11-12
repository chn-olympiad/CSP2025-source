#include<bits/stdc++.h>
using namespace std;
char s[1000000];
long long a[10];
int temp;
bool flagzero=false;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    //cout<<strlen(s)<<endl;
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='0' && s[i]<='9'){
            temp=int(s[i])-'0';
            if(temp!=0){
                flagzero=true;
            }
            a[temp]++;
        }
    }
    if(flagzero){
        for(int i=9;i>=0;i--){
            for(int j=0;j<a[i];j++){
                cout<<i;
            }
        }
    }else{
        cout<<0;
    }

    return 0;
}
