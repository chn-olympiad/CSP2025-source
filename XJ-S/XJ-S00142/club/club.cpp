#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
int T,n;
int a[100005][4];
struct node{
    int idx,val;
    node(int idx,int val):idx(idx),val(val){}
    friend bool operator<(node x,node y){return x.val<y.val;}
};
vector<node>a1,a2,a3;
vector<int>d1,d2,d3;
int ans;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        a1.clear();a2.clear();a3.clear();
        d1.clear();d2.clear();d3.clear();
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++){
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
                a1.push_back(node(i,a[i][1]));
                d1.push_back(a[i][1]-max(a[i][2],a[i][3]));
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
                a2.push_back(node(i,a[i][2]));
                d2.push_back(a[i][2]-max(a[i][1],a[i][3]));
            }
            else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]){
                a3.push_back(node(i,a[i][3]));
                d3.push_back(a[i][3]-max(a[i][1],a[i][2]));
            }
        }
        sort(a1.begin(),a1.end());
        sort(a2.begin(),a2.end());
        sort(a3.begin(),a3.end());
        sort(d1.begin(),d1.end());
        sort(d2.begin(),d2.end());
        sort(d3.begin(),d3.end());

        int cnt1=0,cnt2=0,cnt3=0;
        while(cnt1+1<=n/2&&cnt1<a1.size()){
            ans+=a1[cnt1++].val;
        }
        while(cnt2+1<=n/2&&cnt2<a2.size()){
            ans+=a2[cnt2++].val;
        }
        while(cnt3+1<=n/2&&cnt3<a3.size()){
            ans+=a3[cnt3++].val;
        }
        if(cnt1+cnt2+cnt3==n);
        else{
            int sum=cnt1+cnt2+cnt3;
            if(cnt1==n/2){
                for(int i=1;i<=n-sum;i++){
                    ans+=a1[cnt1++].val;
                    ans-=d1[i-1];
                }
            }
            else if(cnt2==n/2){
                for(int i=1;i<=n-sum;i++){
                    ans+=a2[cnt2++].val;
                    ans-=d2[i-1];
                }
            }
            else{
                for(int i=1;i<=n-sum;i++){
                    ans+=a3[cnt3++].val;
                    ans-=d3[i-1];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
