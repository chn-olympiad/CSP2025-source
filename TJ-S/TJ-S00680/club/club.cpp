#include<bits/stdc++.h>
using namespace std;
struct cl{
	long long a,b,c;
	
};
vector<int> a[4],cnt;
int k,ans=0;
int n;
int dp(int x){
		if(x>=n){
			int yu=0; 
			for(int i=1;i<4;i++)
			if((cnt[i]+1)<=k){
			yu=max(yu,a[i][x]);
			}
			cout<<yu<<'\n';
			return yu;
		}else
		for(int i=1;i<4;i++){
		if((cnt[i]+1)<=k){
			cout<<x<<": "<<ans<<' ';
			cnt[i]++;
			int zh=dp(x+1)+a[i][x];
			ans=max(ans,dp(x+1)+a[i][x]);
			cnt[i]--;
			return zh;}
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int y=0;
	cin>>y;
	for(int u=0;u<y;u++){
		ans=0;
		cin>>n;
		k=floor(n/2);
		n+=5;
		a[1].clear();
		a[2].clear();
		a[3].clear();
		cnt.clear();
		a[1].resize(n);
		a[2].resize(n);
		a[3].resize(n);
		cnt.resize(3);
		n-=5;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			cout<<' '<<a[1][i]<<' '<<a[2][i]<<' '<<a[3][i];
		}cout<<n;
		cout<<dp(1)<<'/n';
	}
}
