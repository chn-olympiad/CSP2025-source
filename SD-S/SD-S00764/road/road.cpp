#include <bits/stdc++.h>
using namespace std;
int n,m,k,cnt=0,a[10005],u[1000005],v[1000005],w[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int i=1;i<=n+1;i++){
			cin>>a[i];
		} 
	}
	sort(w+1,w+1+m);
	for(int i=1;i<=m;i++){
		cnt+=w[i];
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
