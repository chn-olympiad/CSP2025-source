#include<bits/stdc++.h>
using namespace std;
int g[109];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	int ans=0;
	for(int j=1;j<=n;j++){
		int cnt=0;
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				int sum=0;
				for(int i=l;i<=r;i++){
					sum^=g[i];
				}
				if(sum==k){
					cnt++;
					l=r+1;
					r++;
				}
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
