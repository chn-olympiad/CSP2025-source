#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[500005];
int vis[500005];
int ans=0;
int ji(int l,int r){
	int num=a[l];
	for(int i=l+1;i<=r;i++){
		num=num^a[i];
	}
	return num;
}
void fill(int l,int r){
	for(int i=l;i<=r;i++){
		vis[i]=1;
	}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		if(vis[l]==1){
			continue;
		}
		for(int r=l;r<=n;r++){
			if(vis[l]==1||vis[r]==1){
				break;
			}
			if(ji(l,r)==k){
				fill(l,r);
				ans++;
				//cout<<l<<" "<<r<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
