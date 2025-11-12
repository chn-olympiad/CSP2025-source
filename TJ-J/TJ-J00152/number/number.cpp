#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(isdigit(s[i])){
            a[s[i]-'0']++;
        }
    }
    for(int j=9;j>=0;j--){
        for(int i=1;i<=a[j];i++){
            cout<<j;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
