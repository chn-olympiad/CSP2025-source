#include<bits/stdc++.h>
using namespace std;
const int N = 1e4,M = 1e6;
int n,m,k;
int ans;
int u,v,w;
int road[N * N + 10];
int main(){
	memset(road,-1,sizeof road);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	if(k == 0){
		int worth[m];
		for(int i = 1 ; i <= m ; i ++){
			scanf("%d %d %d",&u,&v,&worth[i]);
		}
		sort(worth + 1,worth + m + 1);
		int ans = 0;
		for(int i = 1 ; i <= n - 1; i ++){
			ans += worth[i];
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int i = 1 ; i <= m ; i ++){
		scanf("%d %d %d",&u,&v,&w);
		if(u > v){
			int ls = u;
			u = v;
			v = ls;
		}
		//cout<<(u - 1) * n + v - 1<<endl;
		road[(u - 1) * n + v - 1] = w;
	}
	int a[N],c;
	for(int i = 1 ; i <= k ; i ++){
		scanf("%d",&c);
		for(int j = 1 ; j <= n ; j ++){
			scanf("%d",&a[j]);
			//cout<<a[j]<<" "<<j<<endl;
		}
		for(int i = 1 ; i <= n ; i ++){
			for(int j = i + 1;j <= n ; j ++ ){
				if(road[(i - 1) * n + j - 1] == -1) road[(i - 1) * n + j - 1] = c + a[i] + a[j];
				else road[(i - 1) * n + j - 1] = min(road[(i - 1) * n + j - 1],c + a[i] + a[j]);
			}
		}
	}
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n; j ++){
			cout<<road[i * n + j]<<" ";
		}
		cout<<endl;
	}
	sort(road,road + n * n);
	int i = 0;
	while (road[i] == -1) i ++;
	int nww = n - 1;
	while(nww --){
		ans += road[i];
		i ++;
	}
	cout<<ans<<endl;
	return 0;
}