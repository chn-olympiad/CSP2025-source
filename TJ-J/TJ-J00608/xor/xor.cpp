#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500015],b[500015],ans;
bool q,q1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1,b;i<=n;i++){
		cin>>b;
		if(b==k)ans++;
		a[i]=a[i-1]^b;
		if(b!=1)q=1;
		if(b>2)q1=1;
	}
	if(!q1&&k<2){
		cout<<ans;
	}
	else if(!q&&k==0)cout<<0;
	else{
		for(int l=1;l<=n;l++){
			int u=0;
			for(int i=l,j=l-1;i<=n;i++){
				if((a[i]^a[j])==k){
					j=i;
					u++;
				}
			}
			if(u>ans)ans=u;
		}
		cout<<ans;
	}
	return 0;
}
