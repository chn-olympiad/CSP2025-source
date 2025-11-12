#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],b[505],cnt,ent,ans,sum[505];
char c[505];
bool vis[505],flag[15];
void dfs(int x,int step){
	vis[x]=1;
	b[step]=x;
	if(step==n){
		cnt=0;
		ent=0;
		for(int i=1;i<=n;i++){
			if(c[i]=='1'){
				if(ent<a[b[i]]){
					cnt++;
				}
				else{
					ent++;
				}
			}
			else{
				ent++;
			}
		}
		if(cnt>=m){
			ans++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,step+1);
		}
	}
	vis[x]=0;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			if(c[i]=='0'){
				sum[i]=sum[i-1]+1;
			}
			else{
				sum[i]=sum[i-1];
			}
		}
		ans=1;
		sort(a+1,a+1+n);
		for(int i=1,cntt;i<=n;i++){
			cntt=0;
			for(int j=n;j>=1;j--){
				if(j<sum[i]){
					break;
				}
				else{
					cntt++;
				}
			}
			ans=ans*(cntt-sum[i])%998244353;
			cout<<cntt<<" "<<sum[i]<<endl;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}

