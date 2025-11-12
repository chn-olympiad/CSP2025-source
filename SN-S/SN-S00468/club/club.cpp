#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+2;
int n,a[N][3],ci[N];
struct node{
	int id,v;
}s[3][N];
int tot[3];
bool cmp(node x,node y){
	return x.v>y.v;
}

signed main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
   ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		
		int ans=0;
		for(int i=0;i<3;i++){
			for(int j=1;j<=tot[i];j++)s[i][j]={0,0};
		}
		for(int i=1;i<=100000;i++)ci[i]=0;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)a[i][j]=0;
		tot[1]=tot[0]=tot[2]=0;
		
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
		for(int i=1;i<=n;i++){
			int mx=0,q=0;
			for(int j=0;j<3;j++){
				if(mx<a[i][j]){
					mx=a[i][j];
					q=j;
				}
			}
			for(int j=0;j<3;j++){
				if(q==j)continue;
				ci[i]=max(ci[i],a[i][j]);
			}
			++tot[q];
			s[q][tot[q]]={i,mx-ci[i]};
			ans+=mx;
		}
		for(int i=0;i<3;i++){
			if(tot[i]>n/2){
				sort(s[i]+1,s[i]+tot[i]+1,cmp);
				for(int j=n/2+1;j<=tot[i];j++){
					ans-=s[i][j].v;
				}
			}
		}
		cout<<ans<<'\n';
	}
   return 0;
}
