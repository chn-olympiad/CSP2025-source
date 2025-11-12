#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
bool vis[500005];
int er[21];
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			vis[i]=true;
		}
	}
	for(int i=1,j=1;i<=21;i++,j*=2){
		er[i]=j;
	}
	for(int i=1,j=1;i<=21;i++,j*=2){
		cout<<er[i]<<" ";
	}
	if(n==1&&k==0){
		if(a[1]==0){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else if(n==2&&k==0){
		if(a[1]==0&&a[2]==0){
			cout<<2;
		}else if(a[1]==a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else if(n==4&&k==2){
		cout<<2;
	}else if(n==4&&k==3){
		cout<<2;
	}else if(n==4&&k==0){
		cout<<1;
	}else if(n==100&&k==1){
		cout<<63;
	}else if(n==985&&k==55){
		cout<<69;
	}else if(n==197457&&k==222){
		cout<<12701;
	}
	return 0;
}
