#include<bits/stdc++.h>
using namespace std;
#define FI(x) freopen(x".in","r",stdin);
#define FO(x) freopen(x".out","w",stdout);
int n,p,a[200005],v[200005],maxn;
int DFS(int l,int h){
	if(l>n){
		return h;
	}
//	cout<<l<<" "<<(l>n)<<" "<<h<<"\n";
	if(v[l]==-1){
		maxn=0;
		for(int lx=l;lx<=n;lx++){
			for(int r=lx;r<=n;r++){
				if((a[r]^a[lx-1])==p){
					maxn=max(maxn,DFS(r+1,h+1)); 
				}
			}
		}
		v[l]=maxn;
//		cout<<l<<" "<<maxn<<"\n";
		return maxn;
	}else{
		return v[l];
	}
}
int main(){
	FI("xor");
	FO("xor");
	cin>>n>>p;
	memset(v,-1,sizeof(v));
	for(int i=1,j;i<=n;i++){
		cin>>j;
		a[i]=((j^a[i-1]));
//		cout<<a[i]<<" ";
	}
	cout<<DFS(1,0);
	return 0;
}
