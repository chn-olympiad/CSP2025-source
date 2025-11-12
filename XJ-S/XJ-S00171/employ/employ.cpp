#include <bits/stdc++.h>
using namespace std;
int n,m,k=0;
string s;
int a[505],vis[505];
void dfs(int x,int rx,int tc){
	if(x==n){
		if(rx>=m){
			k++;
			k%=998244353;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				if(s[x]=='1'&&tc<a[i]){
					rx++;
				}else{
					tc++;
				}
				vis[i]=1;
				dfs(x+1,rx,tc);
				vis[i]=0;
				if(s[x]=='1'&&tc<a[i]){
					rx--;
				}else{
					tc--;
				}
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<k;
	
	return 0;
}
//中华人民共和国万岁 
