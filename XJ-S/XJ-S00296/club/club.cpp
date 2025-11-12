#include<bits/stdc++.h>
using std::cout;
using std::sort;
using std::freopen;
using std::max;
using std::vector;
using std::cin;
using std::ios;
const int N = 1e5+10;
int a[N][3];
bool cmp1(int x,int y){
    return a[x][0] - max(a[x][1],a[x][2]) > a[y][0] - max(a[y][1],a[y][2]);
}

bool cmp2(int x,int y){
    return a[x][1] - max(a[x][0],a[x][2]) > a[y][1] - max(a[y][0],a[y][2]);
}

bool cmp3(int x,int y){
    return a[x][2] - max(a[x][0],a[x][1]) > a[y][2] - max(a[y][0],a[y][1]);
}
void solve(){
    int n;
    cin>>n;
    vector<int> v1,v2,v3;
    long long ans =0 ;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        int ma = max(a[i][0],max(a[i][1],a[i][2]));
        ans += ma;
        if(ma == a[i][0]){
            v1.push_back(i);
        }else if(ma == a[i][1]){
            v2.push_back(i);
        }else{
            v3.push_back(i);
        }
    }
    if(v1.size() > n/2){
        sort(v1.begin(),v1.end(),cmp1);
        for(int i = n/2;i < v1.size();i++){
            ans -= a[v1[i]][0] - max(a[v1[i]][1],a[v1[i]][2]);
        }
    }
    if(v2.size() > n/2){
        sort(v2.begin(),v2.end(),cmp2);
        for(int i = n/2;i < v2.size();i++){
            ans -= a[v2[i]][1] - max(a[v2[i]][0],a[v2[i]][2]);
        }
    }
    if(v3.size() > n/2){
        sort(v3.begin(),v3.end(),cmp3);
        for(int i = n/2;i < v3.size();i++){
            ans -= a[v3[i]][2] - max(a[v3[i]][0],a[v3[i]][1]);
        }
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
}