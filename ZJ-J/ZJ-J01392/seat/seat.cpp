#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int N=200005;
const int INF=0x3f3f3f3f;
int a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    int s=a[1];
    int tot=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]>=a[1]) tot++;
    }
    int u=tot/n;
    if(tot%n==0){
        if(u%2==1) printf("%d %d\n",u,n);
        else printf("%d %d\n",u,1);
    }else{
        if(u%2==0) printf("%d %d\n",u+1,tot%n);
        else printf("%d %d\n",u+1,n-tot%n+1);
    }
    return 0;
}
