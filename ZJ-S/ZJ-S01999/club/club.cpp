#include<bits/stdc++.h>
using namespace std;
#define F(i,l,r) for(int i=(l);i<=(r);i++)
#define pb push_back
#define int long long
const int num=110000;
int n,a[3][num],cnt[3],ans,ch[num];
int solve(){
    cin>>n;
    ans=0;
    F(i,0,2)cnt[i]=0;
    F(i,1,n){
        int mx=-1,r=-1;
        F(j,0,2){
            cin>>a[j][i];
            if(a[j][i]>mx)mx=a[j][i],r=j;
        }
        cnt[r]++;
        ans+=mx;
        ch[i]=r;
    }
    if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2)return ans;
    int p=0;
    if(cnt[1]>n/2)p=1;
    else if(cnt[2]>n/2)p=2;
    priority_queue<int,vector<int>,greater<int>>q;
    F(i,1,n)if(ch[i]==p){
        int p1=1,p2=2;
        if(p==1)p1=0;
        if(p==2)p2=0;
        q.push(min(a[p][i]-a[p1][i],a[p][i]-a[p2][i]));
    }
    int dt=cnt[p]-n/2;
    while(dt--){
        int w=q.top();q.pop();
        ans-=w;
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)cout<<solve()<<'\n';
}