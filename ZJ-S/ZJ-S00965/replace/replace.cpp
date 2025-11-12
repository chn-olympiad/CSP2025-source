#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n, q;
    cin>>n>>q;
    vector<pair<string, string>> str(n), proc(q), cpy1(n), cpy2(q);
    for(int i=0; i<n; i++){
        cin>>str[i].first>>str[i].second;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<str[i].first.size(); j++){
            string firsts=str[i].first.substr(j, 1);
            string seconds=str[i].second.substr(j, 1);
            
            if(firsts!=seconds){
                cpy1[i].first.append(firsts);
                cpy1[i].second.append(seconds);
            }
        }
    }for(int i=0; i<q; i++){
        int ans=0;
        vector<pair<string, string>> proc(q), cpy2(q);
        cin>>proc[i].first>>proc[i].second;
        for(int i=0; i<q; i++){
            for(int j=0; j<proc[i].first.size(); j++){
                string firsts=proc[i].first.substr(j, 1);
                string seconds=proc[i].second.substr(j, 1);
                if(firsts!=seconds){
                    cpy2[i].first.append(firsts);
                    cpy2[i].second.append(seconds);
                }
            }
        }for(int i=0; i<n; i++){
            for(int j=0; j<q; j++){
                if(cpy1[i]==cpy2[j]) ans++;
            }
        } cout<<ans<<endl;
    } 
}