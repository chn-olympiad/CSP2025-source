#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=1e5+5;
int n;
int a[N][4],v[4];
int dfs(int now,int s1,int l1,int s2,int l2,int s3,int l3){
    if(now==n+1){
        return s1+s2+s3;
    }
    int res=0;
    if(l1<n/2)res=max(res,dfs(now+1,s1+a[now][1],l1+1,s2,l2,s3,l3));
    if(l2<n/2)res=max(res,dfs(now+1,s1,l1,s2+a[now][2],l2+1,s3,l3));
    if(l3<n/2)res=max(res,dfs(now+1,s1,l1,s2,l2,s3+a[now][3],l3+1));
    return res;
}
int solve(){
    priority_queue<pii,vector<pii>,greater<pii> > pq[4];
    for(int i=1;i<=n;i++){
        //cout<<i<<endl;
        for(int j=1;j<=3;j++){
            //cout<<'\t'<<j<<endl;
            if(pq[j].size()<n/2){
                v[j]=a[i][j];
            }else{
                int maxn=-0x7f7f7f7f;
                for(int k=1;k<=3;k++){
                    //cout<<"\t\t"<<k<<endl;
                    if(j==k)continue;
                    //cout<<pq[j].size()<<endl;
                    //cout<<pq[j].top().first<<' '<<pq[j].top().second<<endl;
                    maxn=max(maxn,-pq[j].top().first+a[pq[j].top().second][k]+a[i][j]);
                }
                v[j]=maxn;
            }
        }
        int mm=-1,mv=0;
        for(int j=1;j<=3;j++){
            if(v[j]>mm){
                mm=v[j];
                mv=j;
            }
        }
        if(pq[mv].size()<n/2)pq[mv].push(make_pair(a[i][mv],i));
        else{
            int maxn=-0x7f7f7f7f,maxv=0;
            for(int k=1;k<=3;k++){
                if(mv==k)continue;
                if(maxn<-pq[mv].top().first+a[pq[mv].top().second][k]+a[i][mv]){
                    maxn=-pq[mv].top().first+a[pq[mv].top().second][k]+a[i][mv];
                    maxv=k;
                }
            }
            pq[maxv].push(make_pair(a[pq[mv].top().second][maxv],pq[mv].top().second));
            pq[mv].pop();
            pq[mv].push(make_pair(a[i][mv],i));
        }
    }
    int res=0;
    for(int i=1;i<=3;i++){
        while(!pq[i].empty()){
            res+=pq[i].top().first;
            //cout<<pq[i].top().first<<' ';
            pq[i].pop();
        }
        //cout<<endl;
    }
    return res;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    bool A=true;
    bool B=true;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0)A=false;
            if(a[i][3]!=0)B=false;
        }
        if(n<=10){
            cout<<dfs(1,0,0,0,0,0,0)<<endl;
            continue;
        }
        else if(A){
            int tmp[N];
            for(int i=1;i<=n;i++){
                tmp[i]=a[i][1];
            }
            sort(tmp+1,tmp+n+1);
            int ans=0;
            for(int i=n;i>n/2;i--){
                ans+=tmp[i];
            }
            cout<<ans<<endl;
            continue;
        }
        else{
            cout<<solve()<<endl;
        }
    }
}