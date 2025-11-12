#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int mx=-1;
int orr(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		ans^=a[i];
	}
	return ans;
}
void dfs(int ls,int level){
	if(ls>n){
		mx=max(mx,level);
		return;
	}
	int l=ls,r=ls;
	while(l<=r&&r<=n){
		int orm=orr(l,r);
		if(orm<k) r++;
		else if(orm==k){
			mx=max(mx,level);
			dfs(r+1,level+1);
			l++;
		}
		else l++;
	}
	mx=max(mx,level);
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int f0=0,f1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>0) f0++;
		if(a[i]>1) f1=1;
	}
	if(n<=2&&k==0&&a[1]==1){
		if(n==1) cout<<0;
		else cout<<1;
		return 0;
	}
	if(!f0){
		if(k==0) cout<<n;
		else cout<<0<<endl;
		return 0;
	}
	else if(!f1&&f0==n){
		if(k>1) cout<<0;
		else if(k==1) cout<<n;
		else if(k==0){
			if(n%2==0) cout<<n/2;
			else cout<<n/2+1;
		}
		return 0;
	}
	dfs(1,0);
	cout<<mx;
	return 0;
}
