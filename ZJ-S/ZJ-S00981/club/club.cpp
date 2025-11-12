#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int n;
int ans;
int a[N][3];
int jc[N];
int cnt[3];
bool vis[N];
int m;
pair<int,int>b[N];
void solve(){
    cnt[0]=0;cnt[1]=0;cnt[2]=0;
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++){
        int mx=max(max(a[i][0],a[i][1]),a[i][2]);
        if(a[i][0]==mx)jc[i]=0;
        else if(a[i][1]==mx)jc[i]=1;
        else jc[i]=2;
        cnt[jc[i]]++;
        ans+=mx;
    }
    int idd=-1;
    for(int i=0;i<3;i++){
        if(cnt[i]>n/2){
            idd=i;
            break;
        }
    }
    if(idd==-1){
        cout<<ans<<"\n";
        return;
    }
    m=0;
    for(int i=1;i<=n;i++){
        if(jc[i]==idd){
            if(idd!=0)m++,b[m]=make_pair(a[i][idd]-a[i][0],i);
            if(idd!=1)m++,b[m]=make_pair(a[i][idd]-a[i][1],i);
            if(idd!=2)m++,b[m]=make_pair(a[i][idd]-a[i][2],i);
        }
    }
    sort(b+1,b+m+1);
    int i=0;
    while(cnt[idd]>n/2){
        i++;
        if(vis[b[i].second])continue;
        vis[b[i].second]=1;
        cnt[idd]--;
        ans-=b[i].first;
    }
    cout<<ans<<"\n";
    for(int i=1;i<=n;i++)vis[i]=0;
    return;
}
signed main(){
    // freopen("ex.in","r",stdin);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Tc=1;
    cin>>Tc;
    while(Tc--)solve();
    return 0;
}