#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	int a[1000100],b[1000100],c[1000100];
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i]>>c[i];
		ans+=c[i];
	}
	cout<<ans;
	return 0;
}
