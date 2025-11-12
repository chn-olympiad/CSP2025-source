#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],k,k2,sum[500005],ans;
bool b[500005];
bool chk(int l,int r){
	for(int i=l;i<=r;i++){
		if(b[i]==1) return 0;
	}
	for(int i=l;i<=r;i++){
		b[i]=1;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sum[1]=a[1]^a[1];
	for(int i=1;i<=n;i++){
    	sum[i]=sum[i-1]+a[i]^a[i-1];
	}
	for(int i=i;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>j) continue;
			else if(sum[j]-sum[i-1]==k){
				if(chk(i,j)) ans++;
			}
			else continue;
		}
	}
	cout<<ans;
	return 0;
}
