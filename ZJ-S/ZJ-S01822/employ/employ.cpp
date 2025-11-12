#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[520],b[520],ans[1003],flag[1003],anss=0;
void dfs(int now){
	if(now==n){
		int c=0,w=0;
		//for(int j=0;j<n;j++) cout<<ans[j]<<" ";
		//cout<<endl;
		for(int i=0;i<n;i++){
			//cout<<i<<" "<<c<<endl;
			if(b[i+1]==0) c++;
			else{
				if(c>=ans[i]){
					c++;
				}else{
					w++;
				}
			}
		}
		if(w>=m) anss++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0){
			flag[i]=1;
			ans[now]=a[i];
			dfs(now+1);
			ans[now]=0;
			flag[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		b[i]=x-'0';
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0);
		cout<<anss<<endl;
	return 0;
}
