#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int T,n,a[N][3];
ll f[2][205][205],sum0,sum1,sum2;
void solve1(){
	ll ans=0;
	int p=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		p^=1;
		for(int j=0;j<=min(i,n/2);j++){
			for(int k=0;k+j<=i&&k<=min(i,n/2);k++){
				f[p][j][k]=f[p^1][j][k];
				if(j>0) f[p][j][k]=max(f[p][j][k],f[p^1][j-1][k]+a[i][0]);
				if(k>0) f[p][j][k]=max(f[p][j][k],f[p^1][j][k-1]+a[i][1]);
				if(j+k<i) f[p][j][k]=max(f[p][j][k],f[p^1][j][k]+a[i][2]);
			}
		}
	}
	for(int j=0;j<=n/2;j++){
		for(int k=0;k<=n/2;k++){
			if(j+k>=n/2) ans=max(ans,f[p][j][k]);
		}
	}
	cout<<ans<<"\n";
}
void solve2(){
	priority_queue<int> q;
	for(int i=1;i<=n;i++) q.push(a[i][0]);
	ll ans=0;
	for(int i=1;i<=n/2;i++){
		ans+=q.top();
		q.pop();
	}
	cout<<ans<<"\n";
}
struct node{
	int i,j,val;
	bool operator<(const node &ano)const{
		return val<ano.val;
	}
};
bool vis[N];
int cnt[3],now;
void solve3(){
	memset(vis,0,sizeof(vis));
	cnt[0]=cnt[1]=cnt[2]=0;
	now=0;
	priority_queue<node> q;
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++) q.push({i,j,a[i][j]});
	}
	while(now<n){
		node nn=q.top();
		q.pop();
		if(vis[nn.i]) continue;
		if(cnt[nn.j]<n/2){
			cnt[nn.j]++;
			vis[nn.i]=1;
			now++;
			ans+=nn.val;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		sum0=sum1=sum2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			sum0+=a[i][0];
			sum1+=a[i][1];
			sum2+=a[i][2];
		} 
		if(n<=200) solve1();
		else if(sum1==0&&sum2==0) solve2();
		else solve3();
	}
	return 0;
}
