#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k,sum;
int w[10010],a,u,v,c;
int mx;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		cin >> u >> v >> w[i];
		sum+=w[i];
	}
	for(int i=1;i<=k;i++){
		cin >> c;
		for(int j=1;j<=n;j++){
			cin >> a;
		}
	}
	cout << sum;
	return 0;
}
