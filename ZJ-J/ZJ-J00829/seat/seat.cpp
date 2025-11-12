#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,id;
}a[110];
bool operator < (node x,node y){
    return x.x>y.x;
}
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
        scanf("%d",&a[i].x),a[i].id=i;
    sort(a+1,a+n*m+1);
    int x=0;
    for(int i=1;i<=n*m;i++)
        if(a[i].id==1)
            x=i;
    int zx=0,zy=0;
    zy=x/n;
    if(x%n!=0)
        zy++;
    if(zy%2==1)
        zx=x-(zy-1)*n;
    else
        zx=x-(x-(zy-1)*n);
    printf("%d %d",zy,zx);
    return 0;
}
