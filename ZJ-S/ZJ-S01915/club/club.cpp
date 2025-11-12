#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct M{
	int id;
	int m;
	int z;
}a[N];
bool iusd[N];
int zb[4];
int dp[N];
int ans;
int t;
void dfs(int cur,int rt,int rm){
	if(cur>3*n){
		return ;
	}
	if(rm==0){
		ans=max(ans,rt);
		return ;
	}
	for(int i=1;i<=n;++i){
		if(zb[i]>(n/2)){
			return ;
		}
	}
	if(!iusd[a[cur].id]){
		dfs(cur+1,rt,rm);
		iusd[a[cur].id]=true;
		rt+=a[cur].m;
		zb[a[cur].z]++;
		dfs(cur+1,rt,rm--);
		iusd[a[cur].id]=false;
	}else{
		dfs(cur+1,rt,rm);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t){
		cin >> n;
		for(int i=1;i<=3*n;++i){
			cin >> a[i].m;
			a[i].id=i/3+1;
			a[i].z=i%3;
		}
		for(int j=1;j<=n*3;++j){
			for(int i=1;i<=n*3;++i){
				if(a[i].m<a[i+1].m){
					swap(a[i],a[i+1]);
				}
			}
		}
		dfs(1,n,0);
		cout << ans << endl;
		t--;
	}
	return 0;
}
