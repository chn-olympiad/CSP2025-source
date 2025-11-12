#include <bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]-'0'==0||s[i]-'0'==1||s[i]-'0'==2||s[i]-'0'==3||s[i]-'0'==4||s[i]-'0'==5||s[i]-'0'==6||s[i]-'0'==7||s[i]-'0'==8||s[i]-'0'==9){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        if(a[i]>0){
        	for(int j=1;j<=a[i];j++)cout<<i;
		}
    }
    return 0;
}
