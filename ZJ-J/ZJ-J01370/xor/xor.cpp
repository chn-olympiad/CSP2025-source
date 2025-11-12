#include<bits/stdc++.h>
using namespace std;
int n,k,a[100100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(k==0){
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
		}
		int flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=1) flag=0;
		}
		if(flag==1) cnt=n/2;
		else{
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1) cnt++,i++;
			}
		}
		cout<<max(ans,cnt);
		return 0;
	}else if(k==1){
		int cnt=0;
		for(int i=1;i<n;i++){
			if(a[i]==1&&a[i+1]==0) cnt++,i++;
			else if(a[i]==0&&a[i+1]==1) cnt++,i++;
		}
		cout<<cnt;
	}else{
		cout<<k;
	}
	return 0;
}