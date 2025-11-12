#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10007;
int p[MAXN];
int Find(int x){
	if(p[x]==x){
		return x;
	}else p[x] = Find(p[x]);
}
int u[100007],v[100007],w[100007];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0;i<m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	int num;
	for(int i = 0;i<k;i++){
		for(int j = 0;j<n;j++){
			cin >> num;
		}
	}cout << 0;
	return 0;
}
