#include <bits/stdc++.h>
using namespace std;
///======调试======
bool debug = false;
int suojin = 0;
//=================
int n,a[5005];
long long cnt;
const int MOD = 998244353;
void dfs(int p,int maxa,int sum,int start){
    if(debug){
    }
    if(p>=3&&sum > 2*maxa){
        cnt++;
        cnt = cnt % MOD;
        if(debug){
            for(int i=0;i<suojin;i++){
                cout <<'-';
            }
            cout << "找到新的" << p <<"边形"<<endl;
            for(int i=0;i<suojin;i++){
                cout <<'-';
            }
            cout << "当前个数" << cnt << endl;
            
        }
    }


    for(int i = start;i<n;i++){
        suojin++;
        if(debug){
            for(int i=0;i<suojin;i++){
                cout <<'-';
            }
            cout <<"正才尝试新的边"<< a[i] << " 当前最长边" << max(maxa,a[i]) <<" 当前总边长"<<sum+a[i]<<endl;
            for(int i=0;i<suojin;i++){
                cout <<'-';
            }
            cout <<"当前边数" << p+1 << endl;
        }
        dfs(p+1,max(maxa,a[i]),sum+a[i],i+1);
        suojin--;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    dfs(0,0,0,0);
    cout << cnt;
}