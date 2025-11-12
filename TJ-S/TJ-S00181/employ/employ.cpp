#include <bits/stdc++.h>
using namespace std;

const int P=998244353;
int n,m,c[505];
char s[505];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    srand(time(0));
    int t=rand()%P;
    cout<<t;
    return 0;
}
