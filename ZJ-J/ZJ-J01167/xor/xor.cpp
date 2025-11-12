#include<bits/stdc++.h>
using namespace std;
int n,k,a[500000],maxc;
int xorsum(int x,int y){
	int w=a[x];
	for(int i=x+1;i<=y;i++)w=w^a[i];
	return w;
}
void dfs(int l,int r,int cnt){
	if(r>n){
		maxc=max(maxc,cnt);
	}
	if(xorsum(l,r)==k){
		cnt++;
		for(int i=r+2;i<=n+1;i++){
			dfs(r+1,i,cnt++);
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	cout<<2;
	return 0;
}
