#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
string s[N][3];
int n,m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=m;i++){
        string a,b;
        cin>>a>>b;
        int cnt=0;
        for(int j=0;j<a.size();j++){
            for(int k=1;k<=n;k++){
                // cout<<k<<endl;
                // cout<<a.size()<<" "<<j+s[k][1].size()<<endl;
                if(a.size()>=j+s[k][1].size()){
                    // cout<<k<<endl;
                    if(a.substr(j,s[k][1].size())==s[k][1]){
                        // cout<<k<<endl;
                        string tmp=a.substr(0,j)+s[k][2]+a.substr(j+s[k][1].size());
                        // cout<<tmp<<endl;
                        if(tmp==b)cnt++;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}