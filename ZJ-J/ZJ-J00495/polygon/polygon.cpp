#include<bits/stdc++.h>
const int mod=998244353;
using namespace std;
int n,lis[10000],sum[10000],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>lis[i];sum[i]=lis[i]+sum[i-1];
	}sort(lis,lis+n);
	if(n==3){
		if(lis[1]+lis[2]>lis[3]){
			cout<<1;
		}else{
			cout<<0;
		}return 0;
	}else{
		for(int i=3;i<=n;i++){
			if(sum[i]>2*lis[i]){
				ans++;ans%=mod;
				int a=sum[i-1],b=lis[i];
				for(int j=0;j<i-1;j++){
					for(int k=j+1;k<i;k++){
						int curr=a-sum[j]-lis[k];
						if(curr>b){ans++;ans%=mod;}
					}
				}
			}
		}
	}cout<<ans;
	return 0;
}