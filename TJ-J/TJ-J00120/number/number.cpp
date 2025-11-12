#include <bits/stdc++.h>
using namespace std;
string s;
int c[1000005]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int j=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            int x=s[i]-'0',o=0;
            for(int k=j;k>=0;k--){
                if(x<=c[k]){
                    o=k+1;
                    break;
                }
                else{
                    c[k+1]=c[k];
                }
            }
            c[o]=x;
            j++;
        }
    }
    for(int i=0;i<j;i++){
        cout<<c[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
