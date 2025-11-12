#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N][3],num[3];
pair<int,int> P[N][3];
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=0;i<3;++i) num[i]=0;
        long long ans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<3;++j){
                cin >> a[i][j];
                P[i][j]=make_pair(a[i][j],j);
            }
            sort(P[i],P[i]+3,greater<pair<int,int>>());
            ++num[P[i][0].second];
            ans+=P[i][0].first;
        }
        int o=-1;
        for(int i=0;i<3;++i){
            if(num[i]>n/2) o=i;
        }
        if(o!=-1){
            priority_queue<int> pq;
            for(int i=0;i<n;++i){
                if(P[i][0].second==o) pq.push(P[i][1].first-P[i][0].first);
            }
            for(int tt=0;tt<num[o]-n/2;++tt){
                ans+=pq.top();
                pq.pop();
            }
        }
        cout << ans << '\n';
    }
    return 0;
}