#include <bits/stdc++.h>
using namespace std;
const long long N=1e5+10;
long long T,n,a[N][3],fi,se;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        long long ans=0;
        cin>>n;
        priority_queue<long long,vector<long long>,greater<long long>> pq[3];
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            long long ma=max({a[i][0],a[i][1],a[i][2]}),mi;
            fi=-1e18,se=-1e18;
            for(int j=0;j<3;j++){
                if(a[i][j]>=fi){
                    se=fi;
                    fi=a[i][j];
                }else{
                    se=max(se,a[i][j]);
                }
                if(a[i][j]==ma){
                    mi=j;
                }
            }
            pq[mi].push(fi-se);
            ans+=ma;
        }
        for(int i=0;i<3;i++){
            while(pq[i].size()>n/2){
                ans-=pq[i].top();
                pq[i].pop();
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}