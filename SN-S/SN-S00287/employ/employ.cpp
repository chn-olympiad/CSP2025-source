//惠子轩  SN-S00287  西安铁一中滨河高级中学 
#include <bits/stdc++.h>
using namespace std;
int n, m, a[550],used[550];
string s;int cnt=0;
void dfs(int al,int k ,int p){
	if(p==k){
			return;
	}
	for(int i=1; i<=al; i++){
		if(used[i]==0){
		cnt++;
			used[i]=1;
		
		}	
			dfs(al,k,p+1);
			used[i]=0;
	}
}
int main(){
//	freopen("employ","r",stdin);
//	freopen("employ","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
dfs(n,m,0);
	cout<<cnt%998244353;
	
	
	return 0;
}
