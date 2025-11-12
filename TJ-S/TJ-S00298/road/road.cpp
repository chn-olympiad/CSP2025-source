#include<bits/stdc++.h>
using namespace std;
int u[100010],v[1000010],w[1000010];
int a[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	int ans=2e9,cnt=0;
	if(k!=0){
		for(int i=1;i<=k;i++){
			cnt=0;
			for(int j=1;j<=n+1;j++){
				int x;
				cin >> x;
				cnt+=x;
			}
			ans=min(ans,cnt);
		}
		cout << ans;
	}
	else{
		int ans=0;
		for(int i=1;i<n;i++){
			ans+=w[i];
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
