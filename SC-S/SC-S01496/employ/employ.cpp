#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10,SN=18;
int n,m,c[N],sum[N],vis[N],ans;
string dif;

void dfs(int now){
	if(now>n){
		int givup=0;
		for(int i=1;i<=n;i++){
			if(c[sum[i]]<=givup||dif[i-1]=='0'){
				givup++;
			}
		} 
		if(givup<=n-m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			sum[now]=i;
			dfs(now+1);
			sum[now]=0;
			vis[i]=0;
		}
	} 
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>dif;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
} 