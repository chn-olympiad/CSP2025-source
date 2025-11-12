#include<bits/stdc++.h>
using namespace std;
bool comp(int x,int y){
	return x > y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,c,ans=0;
	cin >> n >> m >> k;
	int a[m+1][3],x[k+1],b[m+1];
	for(int i=1;i<=m;i++) cin >> a[i][1] >> a[i][2] >> b[i];
	cin >> c; 
	for(int i=1;i<=k;i++) cin >> x[i];
	sort(b+1,b+m+1,comp);
	for(int i=1;i<=m-1;i++) ans+=b[i];
	cout << ans;
	return 0; 
}
