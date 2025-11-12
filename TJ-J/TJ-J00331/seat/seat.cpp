#include<bits/stdc++.h>
using namespace std;
int a[110];
struct node{
    int x,y;
}s[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,p=1,q=1,ans;
    cin >> n >> m;
    for (int i = 1; i<=n*m; i++){
        cin >> s[i].x;
        s[i].y=i;
    }
    a[0]=1;
    for (int i = 1; i<=n; i++) a[i]=i;
    for (int i = n; i<=n*2; i++){
        a[i]=n*2-i;
    }
    sort(s+1,s+n*m+1);
    for (int i = 1; i<=n*m; i++) if(s[i].y==1) ans=i;
    cout << (ans-1)/m << " " << a[ans%(n*2)]
    return 0;
}
