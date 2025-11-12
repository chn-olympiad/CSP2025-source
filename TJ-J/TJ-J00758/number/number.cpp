#include<bits/stdc++.h>
using namespace std;
char c;
int j=1;
int s[1010100];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>c){
        if(c>='0'&&c<='9'){
            int a = c-'0';
            s[j++]=a;
        }
    }
    sort(s+1,s+j,greater<int>() );//paixu
    for(int i=1;i<j;i++){
        cout<<s[i];
    }
    return 0;
}
//O(|s|log|s|)
