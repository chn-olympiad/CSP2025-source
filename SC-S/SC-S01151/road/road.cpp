#include<bits/stdc++.h>
using namespace std;
int n,m,k,flaga,sf[10010],s,bh[10010][10010];
struct dl{
    int fr,to,hf;
}d[1000010];
struct jx{
    int jxh,c[10010];
}cj[15];
bool cmp(dl a,dl b){
    if(a.hf<b.hf)return true;
    else return false;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>d[i].fr>>d[i].to>>d[i].hf;
    }
    for(int i=1;i<=k;i++){
        cin>>cj[i].jxh;
        if(cj[i].jxh)flaga=1;
        for(int j=1;j<=n;j++){
            cin>>cj[i].c[j];
            if(cj[i].c[j])flaga=1;
        }
    }
    if(!flaga&&k){
        cout<<"0";
    }else if(!k){
        sort(d+1,d+1+m,cmp);
        int jh=0;
        for(int i=1;i<=m;i++){
            if(!sf[d[i].fr]&&!sf[d[i].to]){
                jh++;
                sf[d[i].fr]=jh;
                sf[d[i].to]=jh;
                s+=d[i].hf;
            }else if(!sf[d[i].fr]||!sf[d[i].to]){
                sf[d[i].fr]=max(sf[d[i].fr],sf[d[i].to]);
                sf[d[i].to]=max(sf[d[i].fr],sf[d[i].to]);
                s+=d[i].hf;
            }else if(sf[d[i].fr]!=sf[d[i].to]&&!bh[sf[d[i].fr]][sf[d[i].to]]){
                s+=d[i].hf;
                bh[sf[d[i].fr]][sf[d[i].to]]=1;
                bh[sf[d[i].to]][sf[d[i].fr]]=1;
            }
        }
        cout<<s;
    }
    return 0;
}
