#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],v[1000010],n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=z;
		a[y][x]=z;
		if(i<=n-1){
			ans=ans+z;
		}
	}
	cout<<ans;
	return 0;
}

