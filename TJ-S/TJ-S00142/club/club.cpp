#include<bits/stdc++.h>

using namespace std;
const int N=200005;
int n,T,lim,ans;
struct people{
    int a,b,c;
}pe[N];
bool cmp1(people x,people y){
    return x.a>y.a;
}
int main(){


    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        ans=0;
        lim=n/2;
        for(int i=0;i<n;i++){
            cin>>pe[i].a>>pe[i].b>>pe[i].c;
        }
        sort(pe,pe+n,cmp1);
        for(int i=0;i<lim;i++){
            ans+=pe[i].a;
        }
        cout<<ans<<"\n";

    }



    return 0;


/*




1
3
3 2 1
2 3 1
4 5 3



*/

}
