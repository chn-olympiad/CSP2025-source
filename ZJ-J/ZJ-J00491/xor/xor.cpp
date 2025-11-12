#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500010],d[500010],vis[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	int cnt=0,cnt1=0,cnt0=0,cnt3=0;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) cnt0++;
		else if(a[i]==1) cnt1++;
		else cnt3++;
		d[i]=a[i]^d[i-1];
	}
	if(cnt3==0){
		if(cnt1==n){
			if(k==1){
				cout<<n;
				return 0;
			}
			if(k==0){
				cout<<n/2;
				return 0;
			}
		}
		if(cnt0==n){
			if(k==1){
				cout<<0;
				return 0;
			}
			if(k==0){
				cout<<n;
				return 0;
			}
		}
	}
	for(int len=1;len<=n;len++){//cunyi
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			int op=0;
			for(int p=i;p<=j;p++){
				if(vis[p]==1)  op=1;
			} 
			if((d[j]^d[i-1])==k&&op==0){
				cnt++;
				for(int p=i;p<=j;p++) vis[p]=1;
			} 
		}	
	}
	cout<<cnt;
	return 0;
}
