#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+10;
int t,n;
long long a[N][5],mx[N];
long long ans;
vector<int> e[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            mx[i]=0;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(a[i][j]>a[i][mx[i]]){
                    mx[i]=j;//三个社团中满意度最高的
                }
                e[j].clear();
            }
        }
        for(int i=1;i<=n;i++){
            ans+=a[i][mx[i]];
            long long maxn=1e9;
            for(int j=1;j<=3;j++){
                if(j==mx[i])
                    continue;
                maxn=min(a[i][mx[i]]-a[i][j],maxn);
            }
            e[mx[i]].push_back(maxn);
        }
        for(int j=1;j<=3;j++){
            if(e[j].size()*2>n){
                sort(e[j].begin(),e[j].end());
                for(int i=0;i<e[j].size()-(n/2);i++)
                    ans-=e[j][i];
            }
        }
        cout<<ans<<"\n";

    }
    return 0;
}