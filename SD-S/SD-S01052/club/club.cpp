//T1
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int N=200,M=5;
int d[N+5][M];
ll f[N+5][N/2+5][N/2+5][N/2+5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int c1=0;c1<=n/2+1;c1++)
			for(int c2=0;c2<=n/2+1;c2++)
			for(int c3=0;c3<=n/2+1;c3++)
				f[i][c1][c2][c3]=0;
				
		bool f1=true,f2=true; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>d[i][j];
			if(d[i][2]!=0)
				f1=false;
			if(d[i][3]!=0)
				f1=f2=false;
		}
		if(f1){
			ll ans=0;
			vector<int> v;
			for(int i=1;i<=n;i++)
				v.push_back(d[i][1]);
			sort(v.begin(),v.end(),greater<int>());
			for(int i=1;i<=n/2;i++)
				ans+=v[i-1];
			cout<<ans<<endl;
			continue;
		}
		
		for(int i=1;i<=n;i++){
			for(int c1=0;c1<=min(n/2,i-1);c1++)
			for(int c2=0;c2<=min(n/2,i-c1-1);c2++){
				int c3=i-c1-c2-1;
				if(c3>n/2) continue;
				f[i][c1+1][c2][c3]=max(f[i][c1+1][c2][c3],f[i-1][c1][c2][c3]+d[i][1]);
				f[i][c1][c2+1][c3]=max(f[i][c1][c2+1][c3],f[i-1][c1][c2][c3]+d[i][2]);
				f[i][c1][c2][c3+1]=max(f[i][c1][c2][c3+1],f[i-1][c1][c2][c3]+d[i][3]);
			}
		}
		ll ans=0;
		for(int c1=0;c1<=n/2;c1++)
		for(int c2=0;c2<=min(n/2,n-c1);c2++){
			int c3=n-c1-c2;
			if(c3>n/2) continue;
			ans=max(ans,f[n][c1][c2][c3]);
		}
		cout<<ans<<endl;
	}

	return 0;
}

