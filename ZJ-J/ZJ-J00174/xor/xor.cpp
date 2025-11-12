#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1005],ans,A[1005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=1;
	while(l<=r&&r<=n){
		int OR=0,flag=0;
		for(int i=l;i<=r;i++){
			OR=OR^a[i];
		}
		if(OR==k) {
			for(int i=l;i<=r;i++){
				if(!A[i]) A[i]=1;
				else{
					flag=1;
					l++,r=l;
					break;
				}
			}	
			if(!flag) ans++,l++,r=l;
		}
		else {
			if(r==n) l++,r=l;
			else r++;
		}
	}
	cout<<ans;
	return 0;
}
