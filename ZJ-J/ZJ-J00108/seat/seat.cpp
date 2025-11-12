#include<bits/stdc++.h>
using namespace std;
const int MAXN=10+5;
int n,m,k;
vector<int>v(MAXN);
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++) scanf("%d",&v[i]);
    k=v[0];
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<n*m;i++) if(v[i]==k){
        k=i;
        break;
    }
    int x=0,y=0;
    for(int i=0;i<n*m;i++){
        if(i==k) break;
        if((x==0&&y%2==1)||(x==n-1&&y%2==0)) y++;
        else if(y%2) x--;
        else x++;
    }
    printf("%d %d",y+1,x+1);
    return 0;
}
