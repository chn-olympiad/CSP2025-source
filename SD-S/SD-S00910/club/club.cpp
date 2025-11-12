#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+9;
ll m=3;
ll t,n,ans;
ll a[N][5];
ll d[4];
bool ok=0;
bool d2,d3;
struct node{
	ll id,val;
}e[N][5];
bool cmp(node A,node B){
	return A.val>B.val;
}
void dfs(ll x,ll cnt){
	if(x>n){
		ans=max(ans,cnt);
		return ;
	}
	for(int i=1;i<=m;i++){
		d[i]++;
		if(d[i]>n/2){
			d[i]--;
			continue;
		}
		dfs(x+1,cnt+a[x][i]);
		d[i]--;
	}
	return ;
}
void clean_all(){
	n=0;ans=0;d2=0;d3=0;m=3;ok=0;
	memset(a,0,sizeof a);
	memset(d,0,sizeof d);
	return ;
}
void bl(){
	dfs(1,0);
	cout<<ans<<endl;
	return ;
}
void dfs2(ll x,ll cnt){
	if(ok) return ;
	if(x>n){
		ans=max(ans,cnt);
		ok=1;
		return ;
	}
	for(int i=1;i<=m;i++){
		d[e[x][i].id]++;
		if(d[e[x][i].id]>n/2){
			d[e[x][i].id]--;
			continue;
		}
		dfs2(x+1,cnt+e[x][i].val);
		d[i]--;
	}
	return ;
}
void solve_A(){
	ll b[N];
	for(int i=1;i<=n;i++){
		b[i]=a[i][1];
	}
	sort(b+1,b+n+1);
	for(int i=n;i>=n/2+1;i--){
		ans+=b[i];
	}
	cout<<ans<<endl;
	return ;
}
void zj(){
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			e[i][j].id=j;
			e[i][j].val=a[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		sort(e[i]+1,e[i]+4,cmp);
	}
	dfs2(1,0);
	cout<<ans<<endl;
	return; 
}
ll ans2;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		clean_all();
		cin>>n;
		for(int i=1;i<=n;i++){
			ll mmax=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				mmax=max(mmax,a[i][j]);
			}
			ans2+=mmax;
			if(a[i][2]!=0) d2=1;
			if(a[i][3]!=0) d3=1;
		}
		if(n<=30){
			bl();
		}
		else{
			if(d2==0 && d3==0){
				solve_A();
			}
			else if(n<=200){
				zj();
			}
			else cout<<ans2;
		}
	}
	return 0;
}
