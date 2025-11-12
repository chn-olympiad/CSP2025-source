#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int T,n,k;
int a[maxn][3];
int cnt[3];
int mx,mxi,mmx;
int b[maxn];
long long ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        cnt[0]=0, cnt[1]=0, cnt[2]=0;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>a[i][1]) mx=a[i][0], mxi=0, mmx=a[i][1];
            else mx=a[i][1], mxi=1, mmx=a[i][0];
            if(a[i][2]>mx) mmx=mx, mx=a[i][2], mxi=2;
            else if(a[i][2]>mmx) mmx=a[i][2];
            cnt[mxi]++;
            ans+=mx;
            b[i]=mx-mmx;
        }
        mxi=-1;
        k=n/2;
        if(cnt[0]>k) mxi=0, k=cnt[0]-k;
        else if(cnt[1]>k) mxi=1, k=cnt[1]-k;
        else if(cnt[2]>k) mxi=2, k=cnt[2]-k;
        if(mxi==-1) cout<<ans<<endl;
        else{
            sort(b+1,b+1+n);
            for(int i=1;i<=k;i++){
                ans-=b[i];
            }
            cout<<ans<<endl;
        } 
    }
    return 0;
}