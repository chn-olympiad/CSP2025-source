#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
typedef long long ll;
int t,n;
int yangfeiting=0; // %yangfeiting %yangfeiting 
struct p{
    int dx,dy,dxp,maxp;
    // dx mincha dy maxcha
}st[MAXN];
bool cmp(p a,p b){
    return a.dx<b.dx;
}
int main(){ 
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        yangfeiting=0;
        int cnta=0,cntb=0,cntc=0;
        cin >> n;   
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin >> a >> b >> c;
            if(a>=b && a>=c){
                cnta++;
                yangfeiting+=a;
                st[i].maxp=1;
                if(a-b>=a-c){
                    st[i].dx=a-c;
                    st[i].dxp=3;
                }else{
                    st[i].dx=a-b;
                    st[i].dxp=2;
                }
            }else if(b>=a && b>=c){
                cntb++;
                yangfeiting+=b;
                st[i].maxp=2;
                if(b-a>=b-c){
                    st[i].dx=b-c;
                }else{
                    st[i].dx=b-a;
                }
            }else{
                cntc++;
                yangfeiting+=c;
                st[i].maxp=3;
                if(c-a>=c-b){
                    st[i].dx=c-b;
                }else{
                    st[i].dx=c-a;
                }
            }
        }
        int maxpos;
        if(max(cnta,max(cntb,cntc))<=n/2){
            cout << yangfeiting << endl;
            continue;
        }
        if(cnta>=cntb && cnta>=cntc) maxpos=1;
        else if(cntb>=cnta && cntb>=cntc) maxpos=2;
        else maxpos=3;
        int xx=max(cnta,max(cntb,cntc))-n/2;
        sort(st+1,st+n+1,cmp);
        int tot=0;
        for(int i=1;i<=n;i++){
            if(st[i].maxp!=maxpos) continue;
            yangfeiting-=st[i].dx;
            tot++;
            if(tot==xx) break;
        }
        cout << yangfeiting << endl;
    }
    fclose(stdin);
    fclose(stdout);


    return 0;
}
