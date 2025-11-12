#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n;
int a[maxn][4];
ll ans;
void dfs(int st,ll sum,int f1,int f2,int f3){
	if (st==n+1){
		ans=max(ans,sum);
		return;
	}
	if (f1+1<=n/2) dfs(st+1,sum+a[st][1],f1+1,f2,f3);
	if (f2+1<=n/2) dfs(st+1,sum+a[st][2],f1,f2+1,f3);
	if (f2+1<=n/2) dfs(st+1,sum+a[st][3],f1,f2,f3+1);
}
void deal1(){
	dfs(1,0,0,0,0);
	cout<<ans;
}
ll dp[205][205][205];
void deal2(){
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=n;i++){
		for (int f1=0;f1<=n/2;f1++){
			for (int f2=0;f2<=n/2;f2++){
				int f3=i-f1-f2;
				if (f3>n/2) continue;
				dp[f1][f2][f3]=max(dp[f1][f2][f3],
				max(dp[f1==0?n+1:f1-1][f2][f3]+a[i][1],
				max(dp[f1][f2==0?n+1:f2-1][f3]+a[i][2],dp[f1][f2][f3==0?n+1:f3-1]+a[i][3])));
			}
		}
	}
	for (int f1=0;f1<=n/2;f1++){
		for (int f2=0;f2<=n/2;f2++){
			int f3=n-f1-f2;
			if (f3>n/2) continue;
			ans=max(ans,dp[f1][f2][f3]);
		}
	}cout<<ans;
}
struct node{
	int a1,a2,a3;
};
bool cmp(node a,node b){
	if (a.a3<=b.a3) return true;
	return false;
}
void deal3(){
	vector<int> v;
	for (int i=1;i<=n;i++){
		v.push_back(a[i][1]);
	}sort(v.begin(),v.end());
	ll sum=0;
	for (int i=0;i<n/2;i++){
		sum+=v[i];
	}cout<<sum;
}
void deal4(){
	vector<node> v; 
	for (int i=1;i<=n;i++){
		a[i][3]=a[i][1]-a[i][2];
		v.push_back((node){a[i][1],a[i][2],a[i][3]});
	}
	sort(v.begin(),v.end(),cmp);
	ll sum=0;
	for (int i=0;i<n/2;i++){
		sum+=v[i].a2;
	}for (int i=n/2;i<n;i++){
		sum+=v[i].a1;
	}cout<<sum;
}
void solve(){
	ans=0;
	cin>>n;
	ll sum2=0,sum3=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			cin>>a[i][j];
		}sum2+=a[i][2];
		sum3+=a[i][3];
	}
	if (n<=30) deal4();
	else if (sum2==0) deal3();
	else if (sum3==0) deal4();
	else deal2();
	cout<<endl;
}
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while (t--){
		memset(a,0,sizeof(a));
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
