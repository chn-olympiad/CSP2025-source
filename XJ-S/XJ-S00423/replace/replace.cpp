#include<bits/stdc++.h>
using namespace std;
int beauty(int x,int y){
    if(x==y){
        return x%y;
    }
    beauty(x-y,fabs(y%x));
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    string s[200005][5],t[200005][5];
    cin>>n>>q;
    for(int i=0;1;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=0;1;i++){
        cin>>t[i][0]>>t[i][1];
    }
    for(int i=0;i<q;i++){
        int u=beauty(beauty(t[i],s[i]));
        int yop=beauty(i,i+q%n)
        while(i){
            cout<<(u-yop)/2;
            break;
        }
        cout<<endl;
    }
    return 0;
}
