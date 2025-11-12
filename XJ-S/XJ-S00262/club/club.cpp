#include<bits/stdc++.h>
using namespace std;
int t;
int n;
const int N=1e5+10;
int maxx;
class node {
public:
    int a,b,c;
}s[N];
bool cmpa(node a,node b) {
   return a.a>b.a;
}
void dfs(int m,int A,int B,int C,int val) { //1-4 point
    if(!m) {
        // cout<<A<<" "<<B<<" "<<C<<endl;
        maxx=max(maxx,val);
        return;
    }
    if(A+1<=n/2) {
        dfs(m-1,A+1,B,C,val+s[m].a);
    }
    if(B+1<=n/2){
        dfs(m-1,A,B+1,C,val+s[m].b);
    }
    if(C+1<=n/2) {
        dfs(m-1,A,B,C+1,val+s[m].c);
    }
    return;
}
void A12() {        //12  point
    sort(s+1,s+1+n,cmpa);
    for(int i=1;i<=n/2;i++) {
        maxx+=s[i].a;
    }

}
int main() {
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--) {
        maxx=0;
        memset(s,0,sizeof(s));
        cin>>n;

        for(int i=1;i<=n;i++) {
            cin>>s[i].a>>s[i].b>>s[i].c;
        }
        if(n>=0) {
            A12();
        } else {
            dfs(n,0,0,0,0);
        }
        cout<<maxx<<endl;
    }
    return 0;
}