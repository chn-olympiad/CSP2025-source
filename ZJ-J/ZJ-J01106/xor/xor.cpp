#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e5+10;
bitset<MAXN> vis;
int main(){
    vector<int> num, px;
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    num.resize(n+1);
    px.resize(n+1);
    bool flagA = true;
    bool flagB = true;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        px[i] = px[i-1]^num[i];
        if(num[i]!=1)flagA = false;
        if(num[i]>1)flagB = false;
    }
    if(flagA){
        cout<<n/2;
        return 0;
    }else if(flagB){
        if(k == 0){
            int cnt = 0;
            for(int i=1;i<=n;i++){
                if(num[i] == 0)cnt++;
                else if(num[i]==1 && num[i-1]==1){
                    cnt++;
                    num[i] = 0;
                }
            }
            cout<<cnt;
        }
        else{
            int cnt = 0;
            for(int i=1;i<=n;i++){
                if(num[i] == 1)cnt++;
            }
            cout<<cnt;
        }
        return 0;
    }
    
    int cnt = 0;
    for(int len=1;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r = l+len-1;
            bool flag = false;
            for(int i=l;i<=r;i++){
                if(vis[i]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                continue;
            }
            if((px[r]^px[l-1]) == k){
                for(int i=l;i<r;i++){
                    vis[i] = true;
                }
                cnt++;
            }
        } 
    }
    cout<<cnt<<endl;
    return 0;
}
// 做一个前缀异或和
// 由于 x^y^z 如果要获得 y^z 只要再异或一次 x 就可以，故成立
// 可以尝试去遍历每个区间，如果当前区间的长度小且成立，则打标记