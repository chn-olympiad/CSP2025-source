#include<bits/stdc++.h>
using namespace std;
int vis[11],v[11];
int cnt=0;
int n,m;
string s;
int ans;
int a[1005];
short r[10000005][10];
int w[100];
void dfs(int x){
	if(x==n+1){
		cnt++;
		for(int i=1;i<=n;i++){
			r[cnt][i]=v[i];
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			v[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	dfs(1);
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<cnt<<'\n';
	for(int i=1;i<=cnt;i++){
		memset(w,0,sizeof(w));
		int p=0,t=0;
		for(int j=1;j<=n;j++){
			if(s[j-1]=='0') p++;
			if(s[j-1]=='1'&&w[j]==0){
				t++;
				if(i==1) cout<<j;
			}
			for(int k=j+1;k<=n;k++){
				if(p>=a[r[i][k]]){
					w[k]=1;
				}
			}
			
		}
//		if(i<=100) cout<<t<<'\n';
		if(t>=m) ans++;
	}
	cout<<ans;
	return 0;
}
