#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 11000,M= 1200000;
ll n,m,k,vis[N],ans = 1e18,vals[N];
vector<pair<ll,ll>>edge[N];
array<ll,4> val[M];
void init(){
	for(int i = 1;i <= n;i++){
		vis[i] = i;
	}
}int find(int x){
	if(x == vis[x]){
		return x;
	}return vis[x] = find(vis[x]);
}void unions(int x,int y){
	x = find(x);
	y = find(y);
	if(x == y){
		return ;
	}
	vis[y] = vis[x];
}
void ku(int key){
	init();ll ans1 = 0,no = 0,sum = n;
	bitset<20>now;
	for(int j = 0;j < k;j++){
		if(key&(1<<j)){
			vis[n+j+1] = n+j+1;
			sum++;
			now[j] = 1;
			ans1 += vals[j+1];
		}
	}
	for(int i = 1;i <= m;i++){
		if(val[i][2] > n){
			int x = val[i][2]-n-1;
			if(!now[x]){
				continue;
			}
		}
		if(find(val[i][1]) != find(val[i][2])){
			no++;
			ans1 += val[i][0];
			unions(val[i][1],val[i][2]);
		}if(no == sum-1){
			break;
		}
	}ans = min(ans,ans1);

}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i = 1;i <= m;i++){
    	int u,v,vals;
    	scanf("%d%d%d",&u,&v,&vals);
    	val[i] = {vals,u,v};
	}int sum = 0;
	for(int i = 1;i <= k;i++){
		scanf("%lld",&vals[i]);
		sum += vals[i];
		for(int j = 1;j <= n;j++){
			int v;
			scanf("%d",&v);
			val[m+i*n-n+j] = {v,j,n+i};
		}
	}m += n*k;
	sort(val+1,val+m+1);
	if(!sum){
		ku((1<<k)-1);
	}else{
		for(int j = 0;j < 1<<k;j++){
			ku(j);
		}
	}


	cout<< ans;


    return 0;
}
