#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
struct clu{
    int x;
    int y;
    int z;
};
*/
int n,m,a,b,c;
/*
bool cmp(int s,int w){
    return s.x<w.x;
    return s.y<w.y;
    return s.z<w.z;
}
*/
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    //clu a[300015];
    cin>>n;
    int cnt;
    while(n--){
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>a>>b>>c
            cnt+=max(a,max(b,c));
        }
    }
    cout<<cnt<<endl;
    return 0;
}
