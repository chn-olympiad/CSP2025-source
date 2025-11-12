#include <bits/stdc++.h>
using namespace std;
string s[100005][5];
int main(){

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    for (int i = 1;i<=m;i++){
        string x,y;
        cin>>x>>y;
        if (x.size() != y.size()){
            cout<<0<<endl;
            continue;
        }
        int cnt = 0;
        for (int j = 1;j<=n;j++){
            if (s[j][1].size()>x.size())continue;

            for (int k = 0;k<=x.size()-s[j][1].size();k++){
                int flag = 1;
                for (int p = k;p<=k+s[j][1].size()-1;p++){
                    if (x[p] != s[j][1][p-k]){
                        flag = 0;
                        break;
                    }
                    if (y[p]!=s[j][2][p-k]){
                        flag = 0;
                        break;
                    }
                }
                for (int p = 0;p<k;p++){
                    if (y[p]!=x[p]){
                        flag = 0;
                        break;
                    }
                }
                for (int p = k+s[j][1].size();p<x.size();p++){
                    if (y[p]!=x[p]){
                        flag = 0;
                        break;
                    }
                }
                if (flag){
                    cnt++;
                        //cout<<j<<" "<<k<<endl;
                }
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
