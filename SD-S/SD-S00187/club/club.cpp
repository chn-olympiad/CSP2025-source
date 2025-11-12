#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5,M=1e3+5;
const int INF=0x3f3f3f3f;
int t;
int n;
int a[N][4];
int b[N];
int ans;
int vis[N];
int mid;
int sum[N];
bool ch1(){
	for(int i=1;i<=n;i++){
		if(a[i][2]==0&&a[i][3]==0&&a[i][1]!=0){
			continue;
		}
		return 0;
	}
	return 1;
}
bool ch2(){
	for(int i=1;i<=n;i++){
		if(a[i][3]==0&&a[i][1]!=0&&a[i][2]!=0){
			continue;
		}
		return 0;
	}
	return 1;
}
void solve1(){
	sort(b+1,b+n+1);
	for(int i=n;i>=n/2;i){
		ans+=b[i];
	}
	cout<<ans<<endl;
}
void solve2(){
	for(int i=1;i<=n;i++){
		ans+=max(a[i][1],a[i][2]);
	}
	cout<<ans;
}
void dfs(int r,int num){
	if(r==n+1){
		ans=max(ans,num);
	}
	else{
		for(int i=1;i<=3;i++){
			sum[i]++;
			if(sum[i]<=mid){
				dfs(r+1,num+a[r][i]);
			}
			sum[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		memset(b,0,sizeof(b));
		cin>>n;
		mid=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i]=a[i][1];
		}
		if(ch1()){
			solve1();
		}
		else if(ch2()){
			solve2();
		}
		else{
			dfs(1,0);
			cout<<ans;
		}
	}
	return 0;
}

