#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
pair<string,string> s[N];
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i].first>>s[i].second;
    }
    while(q--){
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0;i<s1.size();i++){
            for(int k=1;k<=n;k++){
                bool flag=true;
                for(int l=0;l<s[k].first.size();l++){
                    
                }
            }
        }
    }
}