#include <iostream>
using namespace std;
struct path
{
   int link[2];
   int expense;
};

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    scanf("%d%d%d",n,m,k);
    path p[m];
    for (int i=0 ; i<m ;++i){
        int u,v,w;
        path t;
        scanf("%d%d%d",u,v,w);
        t.expense = w;
        t.link[0] = u;
        t.link[1] = v;
        p[i] = t;
    }
    int xz[n+1][k];
    for (int i=0; i<k;++i){
        continue; //
    }
    return 0;
}
