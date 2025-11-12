#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[1000010],b[1000010],c[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	long long ans=0;
	sort(c+1,c+m+1);
	for(int i=1;i<=n-1;i++){
		ans+=c[i];
	}
	cout << ans;
	return 0;
}
