#include<bits/stdc++.h>
using namespace std;
long long qz[500100],ans,k,a,n,q;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		qz[i]=qz[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=q+1;j<=i;j++){
			long long o=qz[i]^qz[j-1];
			if(o==k){
				ans++;
				q=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
