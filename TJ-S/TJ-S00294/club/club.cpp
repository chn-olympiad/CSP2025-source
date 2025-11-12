#include<bits/stdc++.h>
using namespace std;
#define N 100005
int t,n,ans,j_1,j2,j3;
bool flag=true;
struct peo{
    int id,anum,bnum,cnum,pm,pm1;
}s[N];
bool bmp(peo a,peo b){
    return a.bnum<b.bnum;
}
bool cmp(peo a,peo b){
    return a.cnum<b.cnum;
}
bool amp(peo a,peo b){
    return a.anum<b.anum;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i].anum>>s[i].bnum>>s[i].cnum;
        }
        if(s[1].bnum==s[1].cnum&&s[1].cnum==0){
            sort(s+1,s+n+1,amp);
            for(int i=1;i<=n/2;i++){
                ans+=s[i].anum;
            }
            cout<<ans;
        }else{
            sort(s+1,s+n+1,amp);
            for(int i=1;i<=n/2;i++){
                ans+=s[i].anum;
                s[i].id=1;
            }
            sort(s+1,s+n+1,bmp);
            for(int i=1;i<=n/2;i++){
                s[i].pm1=i;
            }
            for(int i=1;i<=n/2;i++){
                s[i].pm=i;
            }
            for(int i=1;i<=n/2;i++){
                if(s[i].id!=1&&s[i].bnum>s[s[i].pm].anum){
                    s[i].id=1;
                    ans+=s[i].bnum;
                }

            }
            sort(s+1,s+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                if(s[i].id==1||s[i].cnum<s[s[i].pm].anum||s[i].cnum<s[s[i].pm1].bnum)continue;
                ans+=s[i].cnum;
            }
            cout<<ans;
        }
    }
    return 0;
}
