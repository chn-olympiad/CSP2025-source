#include <bits/stdc++.h>
using namespace std;
long long t,n,ans,a[100005][5],ma[100005],mi[100005],mid[100005],pla[100005],qs[5];
long long Maxx(long long x,long long y,long long z){
    return max(x,max(y,z));
}
long long Minn(long long x,long long y,long long z){
    return min(x,min(y,z));
}
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q[3];
bool Push_third(int i){
    q[mi[i]].push({a[i][mi[i]+1],i});
    ans+=a[i][mi[i]+1];
    pla[i]=mi[i];
    qs[mi[i]]++;
    return true;
}
bool Push_second(int i){
    if(qs[mid[i]]<n/2){
        q[mid[i]].push({a[i][mid[i]+1]-a[i][mi[i]+1],i});
        ans+=a[i][mid[i]+1];
        pla[i]=mid[i];
        qs[mid[i]]++;
        return true;
    }
    while((pla[q[mid[i]].top().second]!=mid[i]))q[mid[i]].pop();
    if((q[mid[i]].top().first<a[i][mid[i]+1]-a[i][mi[i]+1])){
        int k=q[mid[i]].top().second;
        q[mid[i]].pop();
        q[mid[i]].push({a[i][mid[i]+1]-a[i][mi[i]+1],i});
        Push_third(k);
        ans-=a[k][mid[k]+1];
        ans+=a[i][mid[i]+1];
        pla[i]=mid[i];
        return true;
    }
    return false;
}
bool Push_first(int i){
    if(qs[ma[i]]<n/2){
        q[ma[i]].push({a[i][ma[i]+1]-a[i][mid[i]+1],i});
        ans+=a[i][ma[i]+1];
        pla[i]=ma[i];
        qs[ma[i]]++;
        return true;
    }
    while((pla[q[ma[i]].top().second]!=ma[i]))q[ma[i]].pop();
    if((q[ma[i]].top().first<a[i][ma[i]+1]-a[i][mid[i]+1])){
        int k=q[ma[i]].top().second;
        q[ma[i]].pop();
        q[ma[i]].push({a[i][ma[i]+1]-a[i][mid[i]+1],i});
        ans-=a[k][ma[k]+1];
        if(Push_second(k)==false){
            Push_third(k);
        }
        ans+=a[i][ma[i]+1];
        pla[i]=ma[i];
        return true;
    }
    return false;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        while(!q[0].empty())q[0].pop();
        while(!q[1].empty())q[1].pop();
        while(!q[2].empty())q[2].pop();
        qs[0]=qs[1]=qs[2]=0;
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            pla[i]=0;
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
            if(Maxx(a[i][1],a[i][2],a[i][3])==a[i][1]){
                if(Minn(a[i][1],a[i][2],a[i][3])==a[i][2]){
                    ma[i]=0;
                    mi[i]=1;
                    mid[i]=2;
                }
                else{
                    ma[i]=0;
                    mi[i]=2;
                    mid[i]=1;
                }
            }
            else if(Maxx(a[i][1],a[i][2],a[i][3])==a[i][2]){
                if(Minn(a[i][1],a[i][2],a[i][3])==a[i][1]){
                    ma[i]=1;
                    mi[i]=0;
                    mid[i]=2;
                }
                else{
                    ma[i]=1;
                    mi[i]=2;
                    mid[i]=0;
                }
            }
            else{
                if(Minn(a[i][1],a[i][2],a[i][3])==a[i][2]){
                    ma[i]=2;
                    mi[i]=1;
                    mid[i]=0;
                }
                else{
                    ma[i]=2;
                    mi[i]=0;
                    mid[i]=1;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(Push_first(i)==false){
                if(Push_second(i)==false){
                    Push_third(i);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
