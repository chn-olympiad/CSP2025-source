#include<bits/stdc++.h>
using namespace std;
#define NOIIO
#define MULTI_CASES
#define ll long long 
#define int ll
#define endl '\n'
#define vi vector<int>
#define PII pair<int,pair<int,int> >
const int MaxN=4e5+100;
const int INF=1e9;
const int mod=1e9+7;
int N,M,T=1;
// int a[MaxN].b[MaxN],c[MaxN];
struct node{
    int x,y,z;
}a[MaxN];
inline void Solve(){
    priority_queue<PII,vector<PII>,greater<PII> >q1,q2,q3;

    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
    }
    int ans=0;
    int sum1=0,sum2=0,sum3=0;
    int cha1=0,cha2=0,cha3=0;
    // int id1=0,id2=0,id3=0;
    for(int i=1;i<=N;i++){
        if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
            if(sum1==N/2){
                int cha=q1.top().first;
                int id=q1.top().second.first;
                int pos=q1.top().second.second;
                if(cha<a[i].x){
                    if(id==2){
                        sum2++;
                        q2.push({a[pos].y-a[pos].z,{3,pos}});
                    }
                    if(id==3){
                        sum3++;
                        q3.push({a[pos].z-a[pos].y,{2,pos}});
                    }
                    q1.pop();
                    ans+=a[i].x-cha;
                    cha1=min(a[i].x-a[i].y,a[i].x-a[i].z);
                    if(cha1==a[i].x-a[i].y){
                       q1.push({cha1,{2,i}});
                    }
                    else{
                        // id1=3;
                        q1.push({cha1,{3,i}});
                    }
                    continue;
                }
                else{
                    ans+=max(a[i].y,a[i].z);
                    if(a[i].y>=a[i].z){
                        q2.push({a[i].y-a[i].z,{3,i}});
                        sum2++;
                    }
                    else{
                        q3.push({a[i].z-a[i].y,{2,i}});
                        sum3++;
                    }
                    continue;
                }
            }
            sum1++;
            ans+=a[i].x;
            cha1=min(a[i].x-a[i].y,a[i].x-a[i].z);
            if(cha1==a[i].x-a[i].y){
                q1.push({cha1,{2,i}});
            }
            else{
                // id1=3;
                q1.push({cha1,{3,i}});
            }
        }
        else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
            if(sum2==N/2){
                int cha=q2.top().first;
                int id=q2.top().second.first;
                int pos=q2.top().second.second;
                if(cha<a[i].y){
                    if(id==1){
                        sum1++;
                        q1.push({a[pos].x-a[pos].z,{3,pos}});
                    }
                    if(id==3){
                        sum3++;
                        q3.push({a[pos].z-a[pos].x,{1,pos}});
                    }
                    q2.pop();
                    ans+=a[i].y-cha;
                    cha1=min(a[i].y-a[i].x,a[i].y-a[i].z);
                    if(cha1==a[i].y-a[i].x){
                       q2.push({cha1,{1,i}});
                    }
                    else{
                        // id1=3;
                        q2.push({cha1,{3,i}});
                    }
                    continue;
                }
                else{
                    ans+=max(a[i].x,a[i].z);
                    if(a[i].x>=a[i].z){
                        q1.push({a[i].x-a[i].z,{3,i}});
                        sum1++;
                    }
                    else{
                        q3.push({a[i].z-a[i].x,{1,i}});
                        sum3++;
                    }
                    continue;
                }
            }
            sum2++;
            ans+=a[i].y;
            cha2=min(a[i].y-a[i].x,a[i].y-a[i].z);
            if(cha2==a[i].y-a[i].x){
                // id2=1;
                q2.push({cha2,{1,i}});
            }
            else{
                // id2=3;
                q2.push({cha2,{3,i}});
            }
        }
        else{
            if(sum3==N/2){
                int cha=q3.top().first;
                int id=q3.top().second.first;
                int pos=q3.top().second.second;
                if(cha<a[i].z){
                    if(id==1){
                        sum1++;
                        q1.push({a[pos].x-a[pos].y,{2,pos}});
                    }
                    if(id==2){
                        sum2++;
                        q2.push({a[pos].y-a[pos].x,{1,pos}});
                    }
                    q3.pop();
                    ans+=a[i].z-cha;
                    cha1=min(a[i].z-a[i].x,a[i].z-a[i].y);
                    if(cha1==a[i].z-a[i].x){
                       q3.push({cha1,{1,i}});
                    }
                    else{
                        // id1=3;
                        q3.push({cha1,{2,i}});
                    }
                    continue;
                }
                else{
                    ans+=max(a[i].x,a[i].y);
                    if(a[i].x>=a[i].y){
                        q1.push({a[i].x-a[i].y,{2,i}});
                        sum1++;
                    }
                    else{
                        q2.push({a[i].y-a[i].x,{1,i}});
                        sum2++;
                    }
                    continue;
                }
            }
            sum3++;
            ans+=a[i].z;
            cha3=min(a[i].z-a[i].x,a[i].z-a[i].y);
            if(cha3==a[i].z-a[i].x){
                // id3=1;
                q3.push({cha3,{1,i}});
            }
            else{
                q3.push({cha3,{2,i}});
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
#ifdef NOIIO
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#ifdef MULTI_CASES
    cin>>T;
    while(T--)
#endif
        Solve();
    return 0;
}