#include<bits/stdc++.h>
#define Tie ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
using namespace std;
int mp[100005][4];
int a[100005];
ll maxx=0;
ll sum=0;
int n;
int t;
void dfs(int a,int b,int c,int k,ll sum) {
	if(k>n) {
		maxx=max(maxx,sum);
		return;
	}
	if((a+1)*2<=n) {
		dfs(a+1,b,c,k+1,sum+mp[k][1]);
	}
	if((b+1)*2<=n) {
		dfs(a,b+1,c,k+1,sum+mp[k][2]);
	}
	if((c+1)*2<=n) {
		dfs(a,b,c+1,k+1,sum+mp[k][3]);
	}
	return ;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	Tie
	cin>>t;
	while(t--) {
		maxx=0;
		cin>>n;
		bool f=0;
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=3; ++j) {
				cin>>mp[i][j];
				if((j==2||j==3)&&mp[i][j]!=0) {
					f=1;
				}
			}
		}
		if(f==0) {
			for(int i=1;i<=n;++i){
				a[i]=mp[i][1];
			}
			sort(a+1,a+1+n);
			for(int i=1;i<=n;++i){
				if(i*2>=n){
					sum+=a[i];
				}
			}
			cout<<sum<<'\n';
		} else {
			dfs(0,0,0,1,0);
			cout<<maxx<<'\n';
		}
	}
	return 0;
}
