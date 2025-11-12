#include <bits/stdc++.h>
using namespace std;
int n,m,c[100005],ans=1;
string s;
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
cin>>n>>m;
cin>>s;
for(int i=1;i<=n;i++){
cin>>c[i];
}

for(int i=1;i<=n;i++){
ans*=i;
ans%=998;
ans%=244;
ans%=353;
}
cout<<ans;

	return 0;
}
