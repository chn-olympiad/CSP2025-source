//Ren5Jie4Di4Ling5%
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int inf=2e9;

int T;
int n;
int a[N][3];
int p[N];
int cnt[3];

int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        cnt[0]=cnt[1]=cnt[2]=0;
        int ans=0;
        for(int i=1;i<=n;i++) {
            p[i]=-1;
            int mx=-inf;
            for(int j=0;j<3;j++) {
                scanf("%d",&a[i][j]);
                if(a[i][j]>mx) mx=a[i][j],p[i]=j;
            }
            ans+=mx;
            cnt[p[i]]++;
        }
        pair<int,int> mx={0,0};
        for(int i=0;i<3;i++) mx=max(mx,{cnt[i],i});
        if(mx.first>n/2) {
            vector<int> arr;
            for(int i=1;i<=n;i++) if(p[i]==mx.second) {
                int mx=-inf;
                for(int j=0;j<3;j++) if(j!=p[i]) mx=max(mx,a[i][j]);
                arr.push_back(a[i][p[i]]-mx);
            }
            sort(arr.begin(),arr.end());
            for(int i=0;i<arr.size() && mx.first>n/2;i++) {
                ans-=arr[i];
                mx.first--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//14:47