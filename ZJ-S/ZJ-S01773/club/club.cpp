#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N][3],t,n,cn[3],po[N],m;vector<int>vc;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    for(cin>>t;t--;){
        cin>>n;memset(cn,0,sizeof(cn));m=0;
        for(int i=1;i<=n;++i){
            for(int j=0;j<3;++j)cin>>a[i][j];
            po[i]=0;for(int j=1;j<3;++j)if(a[i][j]>a[i][po[i]])po[i]=j;
            ++cn[po[i]];m+=a[i][po[i]];
        }
        for(int o=0;o<3;++o)if(cn[o]>n/2){
            vc.clear();
            for(int i=1;i<=n;++i)if(po[i]==o){
                int ma=-1e9;
                for(int j=0;j<3;++j)if(j!=o)ma=max(ma,a[i][j]-a[i][po[i]]);
                vc.push_back(ma);
            }
            sort(vc.begin(),vc.end());
            while(cn[o]>n/2)--cn[o],m+=vc.back(),vc.pop_back();
            break;
        }
        cout<<m<<endl;
    }
    return 0;
}