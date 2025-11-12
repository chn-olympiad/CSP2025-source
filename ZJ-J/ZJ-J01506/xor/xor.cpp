#include<bits/stdc++.h>
using namespace std;
long long visr[5005],visl[5005],ans,a[5005],sum[5005],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[j]^sum[j-i])==k){
				int f=0;
				for(int v=1;v<=cnt;v++){
					if((visr[v]<=j&&visr[v]>j-i)||(visl[v]<=j&&visl[v]>j-i)||(visl[v]<i-j&&visr[v]>=j)){
						f=1;
						break;
					}
				}
				if(f) continue;
				visr[++cnt]=j;
				visl[cnt]=j-i+1;
				ans++;
			} 
		}
	}
	cout<<ans;
	return 0;
}
