#include<cstdio>
#include<vector>
#include<algorithm>
std::vector<int>v1,v2,v3;
int n,a1,a2,a3,ans;
void Main(){
    scanf("%d",&n),ans=0;
    v1.clear(),v2.clear(),v3.clear();
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a1,&a2,&a3);//printf("{%d %d %d}",a1,a2,a3);
        if(a1>a2&&a1>a3)ans+=a1,v1.push_back(a1-std::max(a2,a3));
        else if(a2>a3)ans+=a2,v2.push_back(a2-std::max(a1,a3));
        else ans+=a3,v3.push_back(a3-std::max(a1,a2));
    //printf("(%d)",ans);
    }
    
    if(v1.size()>n/2){
        std::sort(v1.begin(),v1.end());
        for(int i=0;i<v1.size()-n/2;i++)ans-=v1[i];
    }
    if(v2.size()>n/2){
        std::sort(v2.begin(),v2.end());
        for(int i=0;i<v2.size()-n/2;i++)ans-=v2[i];
    }
    if(v3.size()>=n/2){
        std::sort(v3.begin(),v3.end());
        for(int i=0;i<v3.size()-n/2;i++)ans-=v3[i];
    }
    printf("%d\n",ans);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)Main();
}