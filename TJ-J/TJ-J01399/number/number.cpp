#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char b[N];
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int ans=0;
    string s;
    cin >> s;
    for(int i=1;i<=s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            b[ans]+=s[i];
            ans++;
        }
    }
    sort(b+1,b+ans,cmp);
    for(int i=0;i<ans-1;i++){
        cout << b[i];
    }
    return 0;
}
