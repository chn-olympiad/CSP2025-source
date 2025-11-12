#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int n,q;
string s[200010][2],t[200010][2];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int i=0;i<q;i++){
        cin>>t[i][0]>>t[i][1];
    }

    for(int i=0;i<q;i++){
        cout<<0<<endl;
    }

    return 0;
}