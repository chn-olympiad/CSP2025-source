#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005];
int n,ans;
void dfs(int cnt,int ret){
	if(cnt>n){
		if(ret>3){
			int cnt2 = 0,mx = 0;
			for(int i = 1;i<=ret-1;i++){
				cnt2+=b[i];
				mx = max(mx,b[i]); 
			}
			if(cnt2>mx*2){
				ans++;
			}		
		}
		return;
	}
	b[ret] = a[cnt];
	dfs(cnt+1,ret+1);
	dfs(cnt+1,ret);
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<ans;
}
