#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[10]={},len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        while(a[i]>0){
            cout<<i;
            a[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
