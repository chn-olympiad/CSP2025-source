#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=222;
ll a[N][4];
ll c[N];
ll f1[N][N][2];
ll f2[N][N][2];
ll n;
ll ans;
void dfs(ll x,ll d1,ll d2,ll d3,ll sum){
	if(x>=n){
		ans=max(ans,sum);
		return;
	}
	if(d1<n/2){
		dfs(x+1,d1+1,d2,d3,sum+a[x+1][1]);
	}
	if(d2<n/2){
		dfs(x+1,d1,d2+1,d3,sum+a[x+1][2]);
	}
	if(d3<n/2){
		dfs(x+1,d1,d2,d3+1,sum+a[x+1][3]);
	}
}

bool cmp(ll x,ll y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		ll s1=0,s2=0,s3=0;
		ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			a[i][1]=a[i][2]=a[i][3]=0;
		}
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			s1+=a[i][1];
			s2+=a[i][2];
			s3+=a[i][3];
		}
		if(s2==0&&s3==0){
			for(ll i=1;i<=n;i++){
				c[i]=a[i][1];
			}
			sort(c+1,c+n+1,cmp);
			for(ll i=1;i<=n/2;i++){
				ans+=c[i];
			}
			cout<<ans<<'\n';
			continue;
		}else if(s3==0){
			for(ll i=1;i<=n;i++){
				for(ll j=n/2;j>=0;j--){
					f1[i][j][0]=max(f2[i-1][j][0],f1[i-1][j][0]);
					if(j>0) f1[i][j-1][1]=max(f1[i-1][j][0],f1[i-1][j][1])+a[i][1];
					
					f2[i][j][0]=max(f2[i-1][j][0],f2[i-1][j][0]);
					if(j>0) f2[i][j-1][1]=max(f2[i-1][j][0],f2[i-1][j][1])+a[i][2];
				}
			}
			cout<<max(f2[n][0][0],f2[n][0][1])+max(f1[n][0][0],f1[n][0][1])<<'\n';
			//continue;
		}
		dfs(0,0,0,0,0);

		cout<<ans<<'\n';
	}
	return 0;
}
//25pts


//1
//4
//1 3 0
//2 4 0
//6 5 0
//3 3 0













//Mom,I'm sorry...
//But I can't do these.
//I'm sorry.
