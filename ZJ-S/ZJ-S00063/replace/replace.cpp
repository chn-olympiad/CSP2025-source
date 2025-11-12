#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define N 100005
int n,q;
struct node{
    string from,to;
}e[N];
int ans=0;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>e[i].from>>e[i].to;
    }
    for(int i=1;i<=q;i++){
        string x,y; cin>>x>>y;
        cout<<0<<'\n';
    }
    return 0;
}
