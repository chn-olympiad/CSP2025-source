#include"bits/stdc++.h"
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a,b,c,ans=0,t;
	cin>>t>>t>>c;
	while(t--){
		cin>>a>>a>>a;
		ans+=a;
	}
	cout<<ans;
	return 0;
}
