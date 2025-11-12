#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
int b=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[b]=s[i]-'0';
            b++;
        }
    }
    sort(a,a+b,cmp);
    for(int i=0;i<b;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
