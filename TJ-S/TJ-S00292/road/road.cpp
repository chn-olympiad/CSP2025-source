#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		ans+=z;
	}
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>y;
		}
	}
	cout<<ans;
	return 0;
}
