#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> a,b,c;
int n;
vector<int>na,nb,nc;//ÐòºÅ£¨ÏÂ±ê £© 
ll ans=0;
void dfs(int pos,ll sum){
	if(na.size()>n/2||nb.size()>n/2||nc.size()>n/2)return;
	if(pos>=n){
		ans=max(ans,sum);
		return;
	}
	na.push_back(pos);
	dfs(pos+1,sum+a[pos]);
	na.pop_back();
	nb.push_back(pos);
	dfs(pos+1,sum+b[pos]);
	nb.pop_back();
	nc.push_back(pos);
	dfs(pos+1,sum+c[pos]);
	nc.pop_back();
	
}
void solve(){
	scanf("%d",&n);
	a.assign(n,0);
	b.assign(n,0);
	c.assign(n,0);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	ans=0;
	na.clear();nb.clear();nc.clear();
	dfs(0,0);
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

