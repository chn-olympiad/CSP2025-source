#include <bits/stdc++.h>
using namespace std;
#define N 100005
int t,n;
int a[N],b[N],c[N];
long long ans=0;
long long qzha[N],qzhb[N],qzhc[N];
bool flag1=1,flag2=1;
bool cmp(int a,int b){
    return a>b;
}
void DFS(int cnt,int an,int bn,int cn,long long sum){
    if(an>n/2||bn>n/2||cn>n/2) return ;
    if(cnt==n){
        ans=max(ans,sum);
        return ;
    }
    DFS(cnt+1,an+1,bn,cn,sum+a[cnt+1]);
    DFS(cnt+1,an,bn+1,cn,sum+b[cnt+1]);
    DFS(cnt+1,an,bn,cn+1,sum+c[cnt+1]);
}
priority_queue<pair<int,int> >q1;
priority_queue<pair<int,int> >q2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        flag1=1;
        flag2=1;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0){
                flag1=0;
                flag2=0;
            }
            if(c[i]!=0){
                flag2=0;
            }
        }
        if(flag1&&flag2){
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n/2;i++){
                ans+=a[i];
            }
            cout<<ans<<"\n";
            continue;
        }else if(flag1){
            for(int i=1;i<=n;i++){
                if(cmp(a[i],b[i])) q1.push(make_pair(a[i],i));
                else q2.push(make_pair(b[i],i));
            }
            for(int i=1;i<=n/2;i++){
                if(!q1.size()) break;
                ans+=q1.top().first;
                q1.pop();
            }
            if(q1.size()){
                q2.push(make_pair(q1.top().first,q1.top().second));
                q1.pop();
                while(q2.size()){
                    ans+=q2.top().first;
                    q2.pop();
                }
            }else{
                for(int i=1;i<=n/2;i++){
                    if(!q2.size()) break;
                    ans+=q2.top().first;
                    q2.pop();
                }
                if(q2.size()){
                    while(q2.size()){
                        ans+=a[q2.top().second];
                        q2.pop();
                    }
                }
            }
            cout<<ans<<"\n";
            continue;
        }else{
            int zong=0,numa=0,numb=0,numc=0;
            DFS(zong,numa,numb,numc,0);
            cout<<ans<<"\n";
        }
    }
	return 0;
}

