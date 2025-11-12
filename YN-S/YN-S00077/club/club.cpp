#include<bits/stdc++.h>
#define INF 0x7fffffff
typedef long long ll;
using namespace std;
const int N=2e5+5;
int T,n,a[N],b[N],c[N];
vector<int> v1,v2,v3;
inline bool cmp(int x,int y){return x>y;}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        v1.clear(); v2.clear(); v3.clear();
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int sum1=0,sum2=0,sum3=0;
        ll ans=0;
        for(int i=1;i<=n;i++){
            int maxn=max(max(a[i],b[i]),c[i]);
            ans+=maxn;
            if(a[i]==maxn){
                sum1++;
                v1.push_back(max(b[i],c[i])-maxn);
            }else if(b[i]==maxn){
                sum2++;
                v2.push_back(max(a[i],c[i])-maxn);
            }else{
                sum3++;
                v3.push_back(max(a[i],b[i])-maxn);
            }
        }
        sort(v1.begin(),v1.end(),cmp);
        sort(v2.begin(),v2.end(),cmp);
        sort(v3.begin(),v3.end(),cmp);
        if(sum1>n/2){
            for(int i=sum1,j=0;i>n/2;i--,j++) ans+=v1[j];
        }else if(sum2>n/2){
            for(int i=sum2,j=0;i>n/2;i--,j++) ans+=v2[j];
        }else{
            for(int i=sum3,j=0;i>n/2;i--,j++) ans+=v3[j];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
