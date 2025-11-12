#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
   int n;
   cin>>n;
   int ans=0;
   for(int i=1;i<=n;i++){
   	ans+=n*i;
   }
   cout<<ans;
	return 0;
}

