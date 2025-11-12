#include<bits/stdc++.h>

using namespace std;

int main(){
    //freopen("nember.in","r",stdin);
    //freopen("nember.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size(),a[n];
    int j=0;
    for(int i=0;i<n;i++){
        if(s[i]-'0'==0||s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9){
            a[j]=s[i]-'0';
            j+=1;
        }
    }
    sort(a[0],a[j]);
    for(int i=j;i>=0;i--){
        cout<<a[i];
    }
    return 0;
}
