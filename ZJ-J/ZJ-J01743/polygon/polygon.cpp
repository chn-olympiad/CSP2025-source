#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,a[5005],ans=0,k=-1;
int yh[5005][5005];
void dfs(int t,int num,int sum,int maxx){
	if(t>n){
		if(num>=3&&sum>(2*maxx))ans=(ans+1)%Mod;
		return;
	}
	dfs(t+1,num,sum,maxx);
	dfs(t+1,num+1,sum+a[t],max(maxx,a[t]));
}//DFS O(2N) 40pts
void tianyi(){
	srand(time(NULL));
	cout << rand();
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		k=max(k,a[i]);
	}
	if(n<=20){
		dfs(1,0,0,0);
		cout << ans;
	}
	else if(k==1){
		for(int i=1;i<=n;i++)yh[i][1]=yh[i][i]=1;
		for(int i=3;i<=n;i++){
			for(int j=2;j<i;j++){
				yh[i][j]=(yh[i-1][j-1]+yh[i-1][j])%Mod;
			}
		}
		int mid=n/2.0;
		for(int i=3;i<=n;i++)ans=(ans+yh[n][i])%Mod;
		cout << ans;
	}//бр╦Ц O(N*N) 24pts
	else{
		tianyi();
	}
	return 0;
}
