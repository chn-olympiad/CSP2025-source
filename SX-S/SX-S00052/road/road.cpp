#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int z,x;
	cin>>z>>x;
	int q,w,e,r,t,ans=0;
	for(int i=1;i<=z;i++){
		cin>>q>>w>>e;
		ans+=e;
	}for(int i=1;i<=z;i++){
		cin>>q>>w>>e>>r>>t;
		ans+=t;
	}cout<<ans<<endl;
}