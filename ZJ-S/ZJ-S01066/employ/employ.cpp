#include<bits/stdc++.h>
using namespace std;
int n,m,a[505];
long long ans;
bool vis[505];
string a1;
int dfs(int q,int d){
	if(d==n+1){
		if(n-q>=m)return 1;
		else return 0;
	}
	long long z=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(q<a[i] && a1[d-1]=='1'){
//				cout<<q;
				z+=dfs(q,d+1);
			}
				
			else{
//				cout<<q;
				z+=dfs(q+1,d+1);
			}
				
			vis[i]=0;
		}
	}
	return z;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a1;
//	cout<<a1[0];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ans=dfs(0,1);
	cout<<ans;
	return 0;
}
