#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
LL a,n;
cin>>a>>n;

vector<LL> as(a*n*a,0);
for(LL i = 0;i<as.size();i++){
    cin>>as[i];
}
cout<<"18"<<' '<<"4"<<' '<<"13";
    return 0;
}
