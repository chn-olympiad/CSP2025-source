#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=205;
int n,T;
int v[N][5];
int dp[N][N][N];
void solvel(){
	for(int i=1;i<=n;i++){
		for(int a=0;a<=min(n>>1,i);a++){
			for(int b=0;b<=min(n>>1,i-a);b++){
				int c=i-a-b;
				if(c<0||c>(n>>1)) continue;
				if(a) dp[a][b][c]=max(dp[a][b][c],dp[a-1][b][c]+v[i][1]);
				if(b) dp[a][b][c]=max(dp[a][b][c],dp[a][b-1][c]+v[i][2]);
				if(c) dp[a][b][c]=max(dp[a][b][c],dp[a][b][c-1]+v[i][3]);
			}
		}
	}
	int ans=0;
	for(int a=0;a<=(n>>1);a++){
		for(int b=0;b<=min(n-a,n>>1);b++){
			int c=n-a-b;
			if(c>(n>>1)) continue;
			ans=max(dp[a][b][c],ans);
			
		}
	}
	cout<<ans<<'\n';
}
vector<int >p;
void solvet(){
	int suma=0,sumb=0,ans=0;
	for(int i=1;i<=n;i++){
		if(v[i][1]>v[i][2]) suma++,ans+=v[i][1];
		else if(v[i][1]==v[i][2]) ans+=v[i][1];
		else sumb++,ans+=v[i][2];
	}
	if(suma<=(n>>1)&&sumb<=(n>>1)){
		cout<<ans<<'\n';return ;
	}
	else if(suma>(n>>1)){
		for(int i=1;i<=n;i++){
			if(v[i][1]>v[i][2]) p.push_back(v[i][1]-v[i][2]);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(v[i][1]<v[i][2]) p.push_back(v[i][2]-v[i][1]);
		}
	}
	sort(p.begin(),p.end());
	int num=max(suma,sumb)-(n>>1);
	for(int u:p){
		ans-=u;num--;
		if(!num) break;
	}
	cout<<ans<<'\n';
	return ;
}
void solve(){
	int ans=0;
	for(int i=1;i<=n;i++) ans+=max(v[i][1],max(v[i][2],v[i][3]));
	cout<<ans<<'\n';
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(dp,0,sizeof(dp));
		bool b=1;
		for(int i=1;i<=n;i++){
			cin>>v[i][1]>>v[i][2]>>v[i][3];
			if(v[i][2]!=0||v[i][3]!=0) b=0;
		}
		if(b) solvet();
		else if(n<=200) solvel();
		else solve();
	} 
	return 0;
}