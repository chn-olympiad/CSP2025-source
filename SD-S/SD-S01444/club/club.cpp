#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll maxn = 100500;
ll A[maxn][4],n,ans,F[maxn];
void dfs(ll cur,ll a,ll b,ll c,ll sum){
	if(cur == n + 1){
		ans = max(ans,sum);
		return;
	}
	if(a < n / 2) dfs(cur + 1,a + 1,b,c,sum + A[cur][1]);
	if(b < n / 2) dfs(cur + 1,a,b + 1,c,sum + A[cur][2]);
	if(c < n / 2) dfs(cur + 1,a,b,c + 1,sum + A[cur][3]);
	return;
}
ll cmp(ll a,ll b){
	return a > b;
}
struct node{
	ll id,val;
	bool operator < (const node & ot)const{
		return val > ot.val;
	}
}B[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T,i,j,spa,spb;
	cin>>T;
	while(T--){
		cin>>n;
		ans = 0;
		spa = spb = 1;
		for(i = 1;i <= n;i++){
			cin>>A[i][1]>>A[i][2]>>A[i][3];
			if(A[i][2]) spa = 0;
			if(A[i][3]) spb = 0;
		}
		if(spa){
			for(i = 1;i <= n;i++) F[i] = A[i][1];
			sort(F + 1,F + n + 1,cmp);
			for(i = 1;i <= n / 2;i++) ans += F[i];
			cout<<ans<<endl;
			continue;
		}
		if(spb){
			for(i = 1;i <= n;i++) B[i] = (node){i,A[i][1] - A[i][2]};
			sort(B + 1,B + n + 1);
			for(i = 1;i <= n / 2;i++) ans += A[B[i].id][1];
			for(i = n / 2 + 1;i <= n;i++) ans += A[B[i].id][2];
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
