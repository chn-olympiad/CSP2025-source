#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a[100005][4];
int dp[2][105][105];
void Max(int &a,int b){
	if(a<b) a=b;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dp[0][0][0]=0;
		
		if(n<=200){
		
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int c1=0;c1<=i&&c1<=n/2;c1++){
				for(int c2=0;c1+c2<=i&&c2<=n/2;c2++){
					if(i-c1-c2>n/2) continue;
					dp[i%2][c1][c2]=0;
					if(c1!=0)
						Max(dp[i%2][c1][c2],dp[(i-1)%2][c1-1][c2]+a[i][1]);
					if(c2!=0)
						Max(dp[i%2][c1][c2],dp[(i-1)%2][c1][c2-1]+a[i][2]);
					if(c1+c2!=i)
						Max(dp[i%2][c1][c2],dp[(i-1)%2][c1][c2]+a[i][3]);
					
					//cout<<c1<<' '<<c2<<' '<<i-c1-c2<<' '<<dp[i%2][c1][c2]<<'\n';
					Max(ans,dp[i%2][c1][c2]);
				}
			}
		}
		cout<<ans<<'\n';
		
		}
		else{
		
		bool f=1,f2=1;
		for(int i=1;i<=n;i++){
			if(a[i][3]!=0){
				f=0,f2=0;
				break;
			}
			else if(a[i][2]!=0){
				f=0;
			}
		}
		if(f){
			vector<int> x;
			for(int i=1;i<=n;i++) x.push_back(a[i][1]);
			sort(x.begin(),x.end());
			int ans=0;
			for(int i=n-1;i>=n/2;i--) ans+=x[i];
			cout<<ans<<'\n';
		}
		else if(f2){
			vector<int> x;
			int ans=0,c1=0,c2=0;
			for(int i=1;i<=n;i++){
				if(a[i][1]>a[i][2]) c1++;
				ans+=max(a[i][1],a[i][2]);
			}
			for(int i=1;i<=n;i++){
				if(c1>n/2&&a[i][1]>=a[i][2]){
					x.push_back(a[i][1]-a[i][2]);
				}
				if(c1<n/2&&a[i][1]<=a[i][2]){
					x.push_back(a[i][2]-a[i][1]);
				}
			}
			sort(x.begin(),x.end());
			int cnt=0;
			while(c1-cnt>n/2) ans-=x[cnt++];
			while(c1+cnt<n/2) ans-=x[cnt++];
			cout<<ans<<'\n';
		}
		else{
			int ans=0,cnt,c[4]={0,0,0};
			for(int i=1;i<=100;i++){
				cnt=0,c[0]=c[1]=c[2]=0;
				for(int j=1;j<=n;j++){
					int x=rand()%3;
					c[x]++;
					if(c[x]>n/2) break;
					cnt+=a[j][x+1];
				}
				ans=max(ans,cnt);
			}
			cout<<ans<<'\n';
		}
		
		}
	}
	return 0;
}