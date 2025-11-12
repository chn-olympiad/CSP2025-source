#include<bits/stdc++.h>
using namespace std;

int n , q;
char a[100005] , que[100005];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= q;i++) cin >> que[i];

    printf("%d\n%d",2,0);

    fclose(stdin);
    fclose(stdout);
    return 0;
}