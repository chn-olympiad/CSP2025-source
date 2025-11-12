#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,t;
long long ans;
pair<int,int>now[4];
vector<int>v[4];
void work(){
    v[1].clear();
    v[2].clear();
    v[3].clear();
    ans = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d%d%d",&now[1].first,&now[2].first,&now[3].first);
        now[1].second = 1;
        now[2].second = 2;
        now[3].second = 3;
        sort(now+1,now+4);
        ans += now[3].first;
        v[now[3].second].push_back(now[3].first-now[2].first);
    }
    for(int i = 1;i <= 3;i++){
        int s = v[i].size();
        if(s > n / 2){
            sort(v[i].begin(),v[i].end());
            for(int j = 0;j < s - n/2;j++) ans -= v[i][j];
        }
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--) work();
    return 0;
}