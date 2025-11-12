#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int t,n,flaga,flagb;
struct pe{
    int c[4];
}p[N];
long long s;
void sr(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].c[1]>>p[i].c[2]>>p[i].c[3];
        if(p[i].c[2]!=0)flaga=1;
        if(p[i].c[3]!=0){
            flaga=1;
            flagb=1;
        }
    }
}
bool cmp(pe a,pe b){
    if(a.c[1]>b.c[1])return true;
    else return false;
}
bool cmp2(pe a,pe b){
    int ax=max(max(a.c[1],a.c[2]),a.c[3]),am=min(min(a.c[1],a.c[2]),a.c[3]),ame=a.c[1]+a.c[2]+a.c[3]-ax-am;
    int bx=max(max(b.c[1],b.c[2]),b.c[3]),bm=min(min(b.c[1],b.c[2]),b.c[3]),bme=b.c[1]+b.c[2]+b.c[3]-bx-bm;
    if(ax-ame>bx-bme)return true;
    else if(ax-ame==bx-bme&&ax>bx)return true;
    else if(ax-ame==bx-bme&&ame-am>bme-bm)return true;
    else if(ax-ame==bx-bme&&ame-am==bme-bm&&ame>bme)return true;
    else if(ax-ame==bx-bme&&ame-am==bme-bm&&ame==bme&&am>bm)return true;
    else return false;
}
void fa_dp(){
    int c1_nu=0,c2_nu=0,c3_nu=0,ma;
    sort(p+1,p+n+1,cmp2);
    for(int i=1;i<=n;i++){
        ma=-1;
        if(c1_nu<n/2&&ma<=p[i].c[1]){
                ma=p[i].c[1];
        }
        if(c2_nu<n/2&&ma<=p[i].c[2]){
                ma=p[i].c[2];
        }
        if(c3_nu<n/2&&ma<=p[i].c[3]){
                ma=p[i].c[3];
        }
        if(c1_nu<n/2&&ma==p[i].c[1])c1_nu++;
        else if(c2_nu<n/2&&ma==p[i].c[2])c2_nu++;
        else if(c3_nu<n/2&&ma==p[i].c[3])c3_nu++;
        s+=ma;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        sr();
        if(!flaga){
            sort(p+1,p+n+1,cmp);
            for(int i=1;i<=n/2;i++){
                s+=p[i].c[1];
            }
        }else{
            fa_dp();
        }
        cout<<s<<endl;
        s=0;
    }
    return 0;
}
