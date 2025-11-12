#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;
const LL Maxn = 1e5+5;
struct nold(){
LL Id,Val;
}Vct[Maxn];
LL getM2(LL a,LL b,LL c,LL mVal) {
if(mVal == a) return max(b,c);
else if(mVal == b) return max(a,c);
else return max(a,b);
}
LL getId(LL Num,LL a,LL b,LL c) {
    if(mVal == a) return max(b,c);
else if(mVal == b) return max(a,c);
else return max(a,b);
}
int main(){
freopen(club.in,"r",stdin);
freopen(club.out,"w",stdout);
ios::sync_whith_stio(false);
cin.tie(nullptr);
cout.tie(nullptr);

LL t,n;
cin>>t;
while(t--){
    cin>>n;
    for(int i = 1;i<=n;++i){
        cin>>a>>b>>c;
        Vct[i][0].val = max(max(a,b),c);
        Vct[i][0].Zb = getId(Vct[i][0].val,a,b,c);
        Vct[i][1].val = getM2();
        if(Vct[i][0].Val==a) Vct[i][1]. Zb= (Vct[i][1].Zb==b?2:3);
            else if(Vct[i][0].Val==b)Vct[i][1].Zb = (Vct[i][1].Zb==a?1:3);
            else Vct[i][1].Zb = (Vct[i][1].Zb==a?1:2);

    }
    sort(Vct+1,Vct+2 return x[0].Vct);
}
return 0;
}
