#include<bits/stdc++.h>
using namespace std;
int n,h=0;
bool v[5010];
int a[1010],b[1010];
void dfs(int x,int k,int w){
	if(x==k+1){
		int g=0,ma=0;
		for(int i=1;i<x;i++){
			g+=b[i];
			ma=max(ma,b[i]);
		}
		if(g>ma*2){
			h++;
			h%=998244353;
		}
		return;
	}
	for(int i=w;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			b[x]=a[i];
			dfs(x+1,k,i);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(1,i,1);
	}
	cout<<h%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
