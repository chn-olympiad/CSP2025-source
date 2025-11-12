#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000005][11];
vector<int> u,v,w;
int c[15],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		u.push_back(x);
		v.push_back(y);
		w.push_back(z);
		ans+=z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=m;j++){
			cin>>a[j][i];
		}
	}
	cout<<z;
	return 0;
}
