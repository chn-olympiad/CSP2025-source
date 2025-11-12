#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int x,y;
	int a[10005]={0};
	int ans=0;
	for(int i=0;i<m;i++){
		cin>>x>>y>>a[i];
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
