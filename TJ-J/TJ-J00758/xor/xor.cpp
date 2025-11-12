#include<bits/stdc++.h>
using namespace std;
int c;
int j=1,n,m,u,k,ans;
int s[200010],a[200010],f[10010][10010];
vector<pair<int,int>> v;
bool check(int x1,int y1,int x2,int y2){
    if((x2<=y1&&x2>=x1)||(y2<=y1&&y2>=x1)){
        return 1;
    }else if((x1<=y2&&x1>=x2)||(y1<=y2&&y1>=x2)){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        f[i][i] = a[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            f[i][j] = abs(s[j]-s[i-1]);
        }
    }
    v.push_back({0,0});
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[i][j]==k){
                //cout<<i<<j<<endl;
                bool flag = 1;
                for(int k=0;k<v.size();k++){
                    if(check(i,j,v[k].first,v[k].second)){
                        //cout<<i<<j<<endl;
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    ans++;
                    //cout<<i<<j<<endl;
                    v.push_back({i,j});
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
