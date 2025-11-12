#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,ans=0;
string s;
int a[N],l[N],vis[N];
void dfs(int k){
	if(k==n+1){
		int q=0,z=0;
		for(int i=1;i<=n;i++){
			if(a[l[i]]>q){
				if(s[i]=='1'){
					z++;
				}else{
					q++;
				}
			}else{
				q++;
			}
			if(z==m){
				ans++;
				break;
			}
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			l[k]=i;
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s="#"+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
