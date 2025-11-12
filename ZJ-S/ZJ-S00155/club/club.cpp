#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5;

int n,a[N][3];

void solve(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j:{0,1,2})scanf("%d",&a[i][j]);
    int ans=0;
    vector<int> vec[3];
    for(int i=0;i<n;i++){
        int p=0,maxn=-1;
        for(int j:{1,2})if(a[i][j]>a[i][p])p=j;
        for(int j:{0,1,2})if(j!=p)maxn=max(maxn,a[i][j]);
        vec[p].push_back(maxn-a[i][p]),ans+=a[i][p];
    }
    for(int i:{0,1,2})if((int)vec[i].size()>n/2){
        sort(vec[i].rbegin(),vec[i].rend());
        ans+=accumulate(vec[i].begin(),vec[i].end()-n/2,0);
    }
    printf("%d\n",ans);
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--)solve();
    return 0;
}