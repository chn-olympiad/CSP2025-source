#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005];
int sum[1000005],cnt;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0){
			if(a[i]!=1){
				flag=0;
			}
		}
		sum[i]=sum[i-1]^a[i];
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			if(a[i]==m){
				cnt++;
			}
		}
		cout<<cnt;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(sum[j]^sum[i]==m){
					cnt++;
					i=j;
				}
			}
		}
		cout<<cnt-1;
	}
	
	
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<" ";
//	}
	
	return 0;
}