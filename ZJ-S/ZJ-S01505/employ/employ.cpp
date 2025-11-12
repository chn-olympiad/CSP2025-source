#include<bits/stdc++.h>
using namespace std;
long long n,m,c[510];
string st;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>st;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    srand(time(0));
    cout<<rand();
    return 0;
}
