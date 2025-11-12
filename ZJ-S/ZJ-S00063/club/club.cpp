#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define pii pair<int,int> 
int T,n,cnt=0;
priority_queue<pii,vector<pii>,greater<pii> >q;
int sum[4];
struct node{
    int x1,x2,x3;
    int id,se,ans;
}a[N];
bool cmp(node x,node y){
    return max({x.x1,x.x2,x.x3})>max({y.x1,y.x2,y.x3});
}
int ref(int i,int d){
    if(d==1) return a[i].x1;
    if(d==2) return a[i].x2;
    return a[i].x3;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        while(!q.empty()) q.pop();
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        cnt=0; 
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x1>>a[i].x2>>a[i].x3;
            if(a[i].x1>=a[i].x2&&a[i].x1>=a[i].x3){ 
                a[i].id=1; sum[1]++;
                if(a[i].x2>=a[i].x3) a[i].se=2;
                else a[i].se=3;
            }
            else if(a[i].x2>=a[i].x1&&a[i].x2>=a[i].x3){ 
                a[i].id=2; sum[2]++;
                if(a[i].x1>=a[i].x3) a[i].se=1;
                else a[i].se=3;
            }
            else if(a[i].x3>=a[i].x2&&a[i].x3>=a[i].x1){
                a[i].id=3; sum[3]++;
                if(a[i].x1>=a[i].x2) a[i].se=1;
                else a[i].se=2;
            }
        }
        int mid=max({sum[1],sum[2],sum[3]});
        if(mid==sum[1]) mid=1;
        else if(mid==sum[2]) mid=2;
        else mid=3;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(a[i].id!=mid){
                a[i].ans=a[i].id;
                continue;
            } 
            else{
                if(cnt<n/2){
                    cnt++;
                    q.push({ref(i,a[i].id)-ref(i,a[i].se),i});
                    a[i].ans=a[i].id;
                }
                else{
                    if(!q.empty()&&ref(i,a[i].id)-ref(i,a[i].se)>q.top().first){
                        pii u=q.top(); q.pop();
                        a[u.second].ans=a[u.second].se; 
                        a[i].ans=a[i].id;
                        q.push({ref(i,a[i].id)-ref(i,a[i].se),i});
                    }
                    else a[i].ans=a[i].se;
                }
            }
        }
        int res=0;

        for(int i=1;i<=n;i++){
            if(a[i].ans==1) res+=a[i].x1;
            else if(a[i].ans==2) res+=a[i].x2;
            else res+=a[i].x3;
        }
        cout<<res<<'\n';
    }
    return 0;
}