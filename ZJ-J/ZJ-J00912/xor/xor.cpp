#include<bits/stdc++.h>
using namespace std;
int n,k,c1,c2;
int a[500010];
bool vis[500010],flag[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int sf=1^3;
	cout<<sf;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(a[i]==1) c1++;
		if(a[i]==0) c2++;
	}
	if(c1==n&&k==0){
		int ans=n/2;
		cout<<ans;
		return 0;
	}
	else if(c2==n&&k==0){
		cout<<n;
		return 0;
	}
	else if(c1+c2==n&&k==0){
		int ans=c2;
		for(int i=1;i<=n;i++){
			if(a[i]==1&&a[i+1]==1&&!vis[i]&&!vis[i+1]){
				ans++;
				vis[i]=true;
				vis[i+1]=true;
			}
		}
		cout<<ans;
		return 0;
	}
	else if(c1+c2==n&&k==1){
		int ans=c1;
		cout<<ans;
		return 0;
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k) ans++;
		}
		cout<<ans;
	}
	return 0;
}
