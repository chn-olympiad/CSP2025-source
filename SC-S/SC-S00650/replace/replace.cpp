#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    srand(time(0));
    for(int i=1;i<=q;i++){
        cout<<rand<<"\n";
    }
    return 0;
}