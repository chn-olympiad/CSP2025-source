// 曹佳琦 SN-S00300 西安市庆华中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[10010],v[10010],w[10010];
int a[10010][10010];
int main(){
	freopen("employ","r",stdin);
	freopen("employ","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<m+1;j++){
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
